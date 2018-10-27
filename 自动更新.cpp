#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<io.h>
#include<windows.h> 
using namespace std; 
string GBKToUTF8(const std::string& strGBK)
{
    string strOutUTF8 = "";
    WCHAR * str1;
    int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
    str1 = new WCHAR[n];
    MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
    n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
    char * str2 = new char[n];
    WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
    strOutUTF8 = str2;
    delete[]str1;
    str1 = NULL;
    delete[]str2;
    str2 = NULL;
    return strOutUTF8;
}


    string&   replace_all(string&   str,const   string&   old_value,const   string&   new_value)     
    {     
        while(true)   {     
            string::size_type   pos(0);     
            if(   (pos=str.find(old_value))!=string::npos   )     
                str.replace(pos,old_value.length(),new_value);     
            else   break;     
        }     
        return   str;     
    }     
string GetProgramDir()   
{    
	char exeFullPath[MAX_PATH];
	string strPath = ""; 
	GetModuleFileName(NULL,exeFullPath,MAX_PATH); 
	strPath=(string)exeFullPath;
 
	int pos = strPath.find_last_of('\\', strPath.length()); 
	return strPath.substr(0, pos);
}
 

void dir(string path) {
	long hFile = 0;
	struct _finddata_t fileInfo;
	string pathName, exdName;
	if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1) {
		return;
	}
	do {
		if(fileInfo.attrib&_A_SUBDIR){ 

		} else {
			string str=fileInfo.name;
			str=replace_all(str,".md","");
			str=replace_all(str,".html","");
			string s=fileInfo.name;
			if(str!="main")
			{
				str="## ["+str+"]("+"index.html?page="+s+")";
			cout <<GBKToUTF8(str)<< endl;
			}
		}

	} while (_findnext(hFile, &fileInfo) == 0);
	_findclose(hFile);
	return;
}
int main() {
	string path=GetProgramDir()+"\\markdown\\索引.md";
	freopen(path.data(),"w",stdout); 
	cout<<"# [index](\\index.html)\n# pages\n# ["<<GBKToUTF8("在线题库")<<"](\\markdown\\"<<GBKToUTF8("在线题库")<<".html)\n";
	path=GetProgramDir()+"\\markdown";
	dir(path);
	return 0;
}
