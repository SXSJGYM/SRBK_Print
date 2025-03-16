#include "core.h"

int main() {
    system("chcp 65001");
    //Code here:
    SRBK_Choice("实话实说/糊弄过去/","");
    SRBK_Choice("城里...吧/怎么说呢/","");
    SRBK_Choice("并不奇怪哦/觉得很可爱/","");
    SRBK_Choice("去钓鱼/去采集野菜/单独行动/","");
    if (SRBK_variable_Selectencoding_Single=="1")
    {
        SRBK_Choice("果然还是不行/这样的话....../","");
    }
    SRBK_Choice("口头致谢/摸摸头/","");
    SRBK_Choice("稍微有点担心/姑且先相信小春的话吧/","");
    SRBK_Choice("让朝武放心/还是别说奇怪的话了/","");
    cout<<"你的选择编码："<<SRBK_variable_Selectencoding<<'\n';
    return 0;
    }