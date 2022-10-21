# tesseract_ocr
tesseractを使用したコンソールOCRアプリです。</br>
大きいファイルを変換するときに、日本語を指定するとなぜかエラーが出るので注意してください。</br>
※今後の課題</br>
・OCRアプリに翻訳機能を追加</br>
・上記の問題の解決</br>
・GUIに変更</br>

<h2>環境構築</h2>
Tesseract_OCRのインストール
<h4>ubuntu-22.04</h4>
・「sudo apt update」</br>
・「sudo apt -y install tesseract-ocr tesseract-ocr-jpn libtesseract-dev libleptonica-dev tesseract-ocr-script-jpan tesseract-ocr-script-jpan-vert」</br>
<h4>Windowsで実行される方は、こちらの記事を参照してください。</h4>
<a href= "https://gammasoft.jp/blog/tesseract-ocr-install-on-windows/">Tesseract OCR をWindowsにインストールする方法</a></br>
※tesseractのincludeパスは、ご自身の環境に合わせて変更していください。
<h2>実行方法</h2>
・g++などで、main.cppをコンパイルしてください。</br>
・「./ocr」</br>
上記コマンドをターミナル上で打てば、実行できます。</br>
※C/C++の実行環境が必要です。
