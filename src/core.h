#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>
#include<conio.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 
using namespace std;
//定义是否需要自动模式变量
bool(SRBK_variable_Auto) = false;
//定义选择编码
string SRBK_variable_Selectencoding;
//定义单次选择编码
string SRBK_variable_Selectencoding_Single;
 
 //定义无等待时间输出函数
void SRBK_Print_Tinykernel(string name, string words, string how) {
    system("cls");
    if (name != "NO_NAME") {
        cout << "【" << name << "】" << '\n';
    } else {
        cout << '\n';
    }
    if (how == "said") {
        cout << " 「";
    }else if(how == "allsaid"){
        cout << " 『";
    }else {
        cout << "  ";
    }
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == '<' and words[i+1] == 'b' and words[i+2] == 'r' and words[i+3] == '>') {
            cout << '\n';
            i += 3;
            cout << "」";
        }else if(words[i] == '<' and words[i+1] == 's' and words[i+2] == 'r' and words[i+3] == '>'){
            if(how == "allsaid"){
                cout << "』";
                cout << '\n';
                cout << " 『";
                i += 3;
            }else{
                cout << "」";
                cout << '\n';
                cout << " 「";
                i += 3;
            }
        }else{
            cout << words[i];
        }
        
    }
    if (how == "said") {
        cout << "」";
    }else if(how == "allsaid"){
        cout << "』";
    }
    cout << '\n';
}
 
 //定义SRBK_Print函数
void SRBK_Print(string name, string words, string how) {
    system("cls");
    // 如果玩家按下了Ctrl键，那么直接跳过对话
    if (KEY_DOWN(VK_CONTROL)) {
        SRBK_Print_Tinykernel(name, words, how);
        this_thread::sleep_for(chrono::milliseconds(22));
        return;
    }
 

    // 打印对话头部分
    if (name != "NO_NAME") {
        cout << "【" << name << "】" << '\n';
    } else {
        cout << '\n';
    }
    if (how == "said") {
        cout << " 「";
    }else if(how == "allsaid"){
        cout << " 『";
    }else {
        cout << "  ";
    }
    
    
    //定义每次等待时间
    int Thistimewait=3;
    //打印对话文字部分
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == '<' and words[i+1] == 'b' and words[i+2] == 'r' and words[i+3] == '>') {
            cout << '\n';
            i += 3;
            cout << "  ";
        }else if(words[i] == '<' and words[i+1] == 's' and words[i+2] == 'r' and words[i+3] == '>'){
            if(how == "allsaid"){
                cout << "』";
                cout << '\n';
                cout << " 『";
                i += 3;
            }else{
                cout << "」";
                cout << '\n';
                cout << " 「";
                i += 3;
            }
        }else{
            cout << words[i];
        }
        this_thread::sleep_for(chrono::milliseconds(Thistimewait));
        //如果按下SPACE、ENTER、鼠标左键、将等待时间调为0，达到跳过逐字输出的效果
        if (KEY_DOWN(VK_SPACE) or KEY_DOWN(VK_RETURN) or KEY_DOWN(VK_LBUTTON)) {
            while (KEY_DOWN(VK_SPACE) or KEY_DOWN(VK_RETURN) or KEY_DOWN(VK_LBUTTON)) {
                
            }
            Thistimewait=0;
        }
        //如果按下Ctrl，直接调用SRBK_Print_tinykernel函数，达到加速效果
        if (KEY_DOWN(VK_CONTROL)) {
            system("cls");
            SRBK_Print_Tinykernel(name, words, how);
            this_thread::sleep_for(chrono::milliseconds(22));
            system("cls");
            return;
        }
        //如果按下A或F6，将自动对话设置为真,如果再次按下，将自动对话设置为假
        if (KEY_DOWN(0x41) or KEY_DOWN(VK_F6)) {
            if (SRBK_variable_Auto) {
                SRBK_variable_Auto=false;
            }else{
                SRBK_variable_Auto=true;
            }    
        }
    }


    //打印对话尾部分
    if (how == "said") {
        cout << "」";
    }else if(how == "allsaid"){
        cout << "』";
    }
    cout << '\n';
 

    //如果SRBK_variable_AUTO为真，那么将自动对话
    if (SRBK_variable_Auto)
    {   this_thread::sleep_for(chrono::milliseconds(100));
        //进度条预准备
        string SRBK_space_length;
        for (int i = 0; i < words.size(); i++)
        {   
            if (words[i] == '<' and words[i+1] == 'b' and words[i+2] == 'r' and words[i+3] == '>'){
                SRBK_space_length="";
            }else if(words[i] == '<' and words[i+1] == 's' and words[i+2] == 'r' and words[i+3] == '>'){
                SRBK_space_length="";
            }else{
                SRBK_space_length+=" ";
            }
        }
        cout<<'\n';
        cout<<SRBK_space_length;
        cout<<"AUTO(Wait)";
        cout<<'\n';
        cout<<SRBK_space_length;
        //输出进度条并循环检测按键
        for (int i = 0; i < 15; i++)
        {
            cout<<"-";
            this_thread::sleep_for(chrono::milliseconds(133));
            //如果按下SPACE、ENTER、鼠标左键，跳过自动对话
            if (KEY_DOWN(VK_SPACE) or KEY_DOWN(VK_RETURN) or KEY_DOWN(VK_LBUTTON)) {
                while (KEY_DOWN(VK_SPACE) or KEY_DOWN(VK_RETURN) or KEY_DOWN(VK_LBUTTON)) {
                    this_thread::sleep_for(chrono::milliseconds(10));
                }
                break;
            //如果按下A或F6，将自动对话设置为假，跳过自动对话
            }else if (KEY_DOWN(0x41) or KEY_DOWN(VK_F6)) {
                SRBK_variable_Auto=false;   
                break;
            //如果按下Ctrl，直接调用SRBK_Print_tinykernel函数，跳过自动对话
            }else if (KEY_DOWN(VK_CONTROL)) {
                SRBK_Print_Tinykernel(name, words, how);
                this_thread::sleep_for(chrono::milliseconds(22));
                break;
            }
        }
        
        system("cls");
        return;

    }else{
        //等待玩家按下空格、回车、鼠标左键、A键、F6键或ctrl键
        while (true) {
        if (KEY_DOWN(VK_SPACE) or KEY_DOWN(VK_RETURN) or KEY_DOWN(VK_LBUTTON)) {
            while (KEY_DOWN(VK_SPACE) or KEY_DOWN(VK_RETURN) or KEY_DOWN(VK_LBUTTON)) {
                this_thread::sleep_for(chrono::milliseconds(10));
            }
            system("cls");
 
            break;
        }
        if (KEY_DOWN(VK_CONTROL)) {
            SRBK_Print_Tinykernel(name, words, how);
            this_thread::sleep_for(chrono::milliseconds(22));
            system("cls");
            break;
        }
        //如果按下A或F6，将自动对话设置为真,如果再次按下，将自动对话设置为假
        if (KEY_DOWN(0x41) or KEY_DOWN(VK_F6)) {
            if (SRBK_variable_Auto) {
                SRBK_variable_Auto=false;
            }else{
                SRBK_variable_Auto=true;
            }    
            system("cls");
            break;
        }
 
        this_thread::sleep_for(chrono::milliseconds(10));
        }
    }
    
    
}
 
//定义SRBK_Choice函数
void SRBK_Choice(string lines,string how){
    system("cls");
    //以/分割lines字符串并输出
    string thisline;
    int thisnumber=0;
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i] == '/'){
            thisnumber++;
            cout<<' '<<thisnumber<<". "<<thisline<<'\n';
            thisline="";
        }else{
            thisline+=lines[i];
        }
    }
    //捕获玩家输入
    int choice;
    cout<<"按下对应数字键选择"<<'\n';
    while (true){
        choice=getch()-48;
        if (choice>0 and choice<=thisnumber)
        {   if(how != "notappend"){
                SRBK_variable_Selectencoding+=to_string(choice);
            }
            SRBK_variable_Selectencoding_Single=to_string(choice);
            break;
        }
    }
}