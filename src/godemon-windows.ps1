echo *************__*************`r`n************/*/*************`n***********/*/**************`n**********/*/____***********`n*********/____**/***********`n*************/*/************`n************/*/*************`n***********/*/**************`n**********/*/***************`n*********/_/****************`n****************************`r`n
$root = Get-Location
echo "What version do you want to install: "
$version = Read-Host
echo "`nDo you want to do this: `n1. Global `n2. Local `n"
echo "`nAnswer: "
$option = Read-Host
wget "https://github.com/Godemon-simplify-your-Go-programming/godemon/archive/$version.zip" -OutFile "$version.zip"

If ($option -eq 2){
    Expand-Archive -Path "$version.zip"
    cd "./$version/godemon-$version"
    go build
    cd "c:\" 
    cd "Program Files" 
    mkdir "godemon"
    mkdir "godemon/logs/"
    mkdir "godemon/bin/"
    cd "$root"
    cd "./$version/godemon-$version"
    <# mv "godemon.exe c:\Program Files\godemon\bin" #>
    <# rm "-r $version" #>
    <#rm "-r $version.zip"#>
}