#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include <tesseract/renderer.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Inputfile{
    public:
        string file; 
        string lang;
        string filename;
        void filepass();
        void langselect();
        void outfile();
};

void Inputfile::outfile(){
    cout << "出力するファイル名を入力してください。" << "\n" << "入力してください。:";
    cin >> filename;
}

void Inputfile::filepass(){
    cout << "変換するファイル名を入力してください。" << "\n" << "入力してください。:";
    cin >> file;
}

void Inputfile::langselect(){
    cout << "使用する言語を選んでください" << "\n";
    cout << "日本語:jpn" << "\n" <<"英語:eng" << "\n" << "入力してください。:";
    cin >> lang;
}



int main()
{
    Inputfile input;
    input.filepass();
    input.outfile();
    const char* input_image = input.file.c_str();
    const char* output_base = input.filename.c_str();
    //const char* datapath = "/usr/share/tesseract-ocr/4.00/tessdata";
    int timeout_ms = 5000;
    const char* retry_config = nullptr;
    //bool textonly = false;
    //int jpg_quality = 92;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    input.langselect();
    if (api->Init(NULL, input.lang.c_str())) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    tesseract::TessTextRenderer *renderer = new tesseract::TessTextRenderer(output_base);

    bool succeed = api->ProcessPages(input_image, retry_config, timeout_ms, renderer);
    if (!succeed) {
      fprintf(stderr, "Error during processing.\n");
      return EXIT_FAILURE;
    }
    api->End();
    return EXIT_SUCCESS;
}