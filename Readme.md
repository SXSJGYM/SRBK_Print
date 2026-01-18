# SRBK_Print(English)
## Introduction  
A simple terminal program for simulating Galgame dialogue output, featuring character-by-character display, dialogue skipping, auto-mode, and other functions.  

## Features  
- **Character-by-character Output**: Displays dialogues character by character  
- **Dialogue Skipping**: Press Spacebar, Enter, or Left Mouse Button to skip character-by-character display and show full text immediately  
- **Auto-mode**: Press 'A' or F6 to toggle auto-mode. In this mode, the program waits 2 seconds, shows a progress bar, then automatically displays the next dialogue  
- **Special Tag Processing**: Handles special tags (`<br>` and `<sr>`) in dialogues for line breaks and paragraph segmentation  

## Usage  
### Using Standard Text Output (SRBK_Print)
**Coding**: Write code in the `main()` function of `main.cpp` using this format:  
```cpp  
SRBK_Print(string Name, string words, string how);  
```  
*Parameters*:  

1. string Name  
   - Character name. Use "NO_NAME" for nameless dialogues (will be replaced with empty line). This field cannot be empty.  
   - Example:  
     ```  
     "GYM"  
     ```  

2. string words  
   - Dialogue content. This field cannot be empty.  
   - Example:  
     ```  
     "TESTMESSAGE"  
     ```  

3. string how  
   - Format specifier:  
     - "said": Wraps text with `「」`  
     - "allsaid": Wraps text with `『』`  
     - Other values: No brackets for inner thoughts  
   - Example:  
     ```  
     "said", "allsaid", ""  
     ```  

*Special Tags*:  
1. `<br>`  
   - Inserts a line break in output  
2. `<sr>`  
   - Creates a new dialogue segment  

*Examples*:  
- Code:  
  ```cpp  
  SRBK_Print("GYM", "Hello, world!", "said");  
  ```  
  Output:  
  ```  
  【GYM】  
  「Hello, world!」  
  ```  
- Code:  
  ```cpp  
  SRBK_Print("NO_NAME", "Hello, world!", "none");  
  ```  
  Output:  
  ```  
    
   Hello, world!  
  ```  
- Code:  
  ```cpp  
  SRBK_Print("GYM", "Hello,<br>world!", "allsaid");  
  ```  
  Output:  
  ```  
  【GYM】  
  『Hello,  
   world!』  
  ```  
- Code:  
  ```cpp  
  SRBK_Print("GYM", "Hello,<sr>world!", "said");  
  ```  
  Output:  
  ```  
  【GYM】  
  「Hello,」  
  「world!」  
  ```  

### Using Choice Function (SRBK_Choice)

Write code in the `main()` function of `main.cpp` in the following format:

``` cpp
SRBK_Choice(string lines, string how);
```
*Parameter Meanings:*

1. string lines

    String type; Option content. Separate options with `/`. Each option must end with `/`.

    Example:

    ``` text
    "Go fishing/Gather wild vegetables/Act alone/"
    ```
1. string how

    String type; Selection mode.

    If set to `notappend`, the **Selection Code (SRBK\_variable\_Selectencoding)** will NOT be appended with this selection's parameter.

    If set to `""`, the **Selection Code (SRBK\_variable\_Selectencoding)** WILL be appended with this selection's parameter.

    Example:

    ``` text
    "notappend" ""
    ```
*Global Variable Description:*

1. Selection Code (SRBK\_variable\_Selectencoding)

    Records the historical encoding of all important selections in the game. It is only appended with the current selection's parameter when the `how` parameter is an empty string `""`.
2. Single Selection Code (SRBK\_variable\_Selectencoding\_Single)

    Records the selection result from this function call. This variable is updated to the chosen number regardless of the `how` parameter's value.

    You can reference these variables in your code at any time to control plot progression and implement other operations.

*Complete Examples:*

Code:

``` cpp
SRBK_Choice("Help the old man/Ignore and leave/", "");
```


Display Effect:

``` text
 1. Help the old man 
 2. Ignore and leave 
 按下对应数字键选择
```

If option 1 is selected:

``` text
 Selection Code (SRBK_variable_Selectencoding) = "1" 
 Single Selection Code (SRBK_variable_Selectencoding_Single) = "1"
```

Code:

``` cpp
SRBK_Choice("Black tea/Coffee/Juice/", "notappend");
```

Display Effect:

``` text
 1. Black tea 
 2. Coffee 
 3. Juice 
 按下对应数字键选择
```

If option 2 is selected:

``` text
Selection Code (SRBK_variable_Selectencoding) = "1" // Remains unchanged 
Single Selection Code (SRBK_variable_Selectencoding_Single) = "2"
```

Code:

``` cpp
// Consecutive choice example
SRBK_Choice("Attack/Defend/", ""); 
SRBK_Choice("Pursue/Retreat/", ""); 
SRBK_Choice("Heal/Rest/", "notappend");
```
If options 1, 2, 1 are selected in order:

``` text
Selection Code (SRBK_variable_Selectencoding) = "12"
Single Selection Code (SRBK_variable_Selectencoding_Single) = "1"
```

*Usage Scenario Explanation:*

1.Use empty string `""`: 

  Suitable for key choices in the main storyline that affect game endings and plot direction.

2.Use `"notappend"`: 

  Suitable for daily conversations, clothing choices, minor choices that don't affect the main plot, etc.

**Compilation**:  
*Environment Requirements*  
- **Windows-only** program. Tested on:  
  ```  
  Microsoft Windows 11 Pro  
  Version 21H2 (OS Build 22000.2538)  
  ```  
- Requires GCC compiler. Tested with:  
  ```  
  g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 7.3.0  
  ```  

*Compilation Command*:  
```  
g++ main.cpp -o main.exe -I ./src  
```  

**Execution**:  
*Run Program*:  
```  
./main.exe  
```  

*Controls*:  
- Press Spacebar/Enter/Left Mouse Button to skip text or proceed  
- Press 'A'/F6 to toggle auto-mode  
- Hold Ctrl for fast-forward 
- When choices are displayed, press number keys 1-9 to select the corresponding option.

## Notes  
- **Windows-only**: Uses Windows API for key detection  
- **Never remove** this line from `main()`:  
  ```cpp  
  system("chcp 65001");  
  ```  
  Prevents text encoding issues.  

## Contribution  
We warmly welcome contributions!  

As a senior high school student (...), this is my first open-source project. Any help with improving the code would be immensely appreciated!  

Please follow these steps:  
1. Fork the repository  
2. Create a branch (`git checkout -b feature-branch`)  
3. Commit changes (`git commit -am 'Add new feature'`)  
4. Push to branch (`git push origin feature-branch`)  
5. Create a Pull Request  

## License  
2-Clause BSD License. See LICENSE file for details.  

## Closing  
This is my first GitHub project! Thank you for reading!
Special thanks:Cheng

# SRBK_Print（简体中文）
## 简介
这是一个简单的终端程序，用于模拟Galgame对话输出，拥有逐字输出对话，跳过对话，自动对话等功能

## 功能
- **逐字输出对话**：程序会逐字逐句地输出对话内容
- **跳过对话**：可以通过按下空格键、回车键或鼠标左键来跳过逐字输出，直接显示完整对话
- **自动对话**：可以通过按下“A”键或F6键来开启或关闭自动对话模式。在自动对话模式下，会等待两秒，显示进度条，并自动显示下一段对话
- **特殊标记处理**：对话内容中可以包含特殊标记（如`<br>`和`<sr>`），程序会根据这些标记进行换行或分段处理

## 使用
### 使用 标准文本输出（SRBK_Print）
按如下格式在`main.cpp`的`main()`函数中编写代码：
``` cpp
SRBK_Print(string Name,string words,string how);
```
*各参数含义*：

1. string name
   
    字符串型；角色名称。如果为`NO_NAME`则表明无名称，将用空行补位。此项不能为空

    示例：
    ``` 
    "GYM"
    ```
2. string words
   
    字符串型；角色所说/所想内容，此项不能为空

    示例：
    ```
    "TESTMESSAGE"
    ```
3. string how

    字符串型；输出格式
    
    如果为`said`则会为角色所说内容加上`「」`
    
    如果为`allsaid`则会为角色所说内容加上`『』`
    
    如果为其他则不会在角色所想内容两侧加括号

    示例：
    ```
    "said" "allsaid" ""
    ```

*特殊标记：*

1. \<br>
   
    在上文`string words`中插入，插入后将在输出时换行
2. \<sr>

    在上文`string words`中插入，
    插入后将在输出时分段

*整体示例：*

- 代码：
    ``` cpp
    SRBK_Print("GYM", "Hello, world!", "said");
    ```
    输出：
    ```
    【GYM】
    「Hello, world!」
    ```
- 代码：
    ``` cpp
    SRBK_Print("NO_NAME", "Hello,world!", "none");
    ```
    输出：
    ```
    
     Hello, world!
    ```
- 代码：
    ``` cpp
    SRBK_Print("GYM", "Hello,<br>world!", "allsaid");
    ```
    输出：
    ```
    【GYM】
    『Hello, 
     world!』
    ```
- 代码：
    ``` cpp
    SRBK_Print("GYM", "Hello,<sr>world!", "said");
    ```
    输出：
    ```
    【GYM】
    「Hello,」
    「world!」
    ```

### 使用 选择支函数（SRBK_Choice）
按如下格式在`main.cpp`的`main()`函数中编写代码：
``` cpp
SRBK_Choice(string lines,string how);
```
*各参数含义*：

1. string lines
   
    字符串型；选项内容。各选项之间使用`/`分割，每个选项必须以/结尾

    示例：
    ``` 
    "去钓鱼/去采集野菜/单独行动/"
    ```
2. string how
   
    字符串型；选择方式。

    如果为`notappend`则不会为`选择编码(SRBK_variable_Selectencoding)`添加本次选择参数

    如果为`""`则会为`选择编码(SRBK_variable_Selectencoding)`添加本次选择参数

    示例：
    ```
    "notappend" ""
    ```

*全局变量说明：*
1. 选择编码(SRBK_variable_Selectencoding)

    记录游戏中所有重要选择的历史编码。只有在how参数为空字符串""时，本次选择才会被追加到此编码中。
2. 单次选择编码(SRBK_variable_Selectencoding_Single)
    
    记录本次函数调用中的选择结果。无论how参数是什么值，此变量都会被更新为本次选择的数字。

  您可以在代码中随时调用以上变量，以方便控制剧情走向以及实现其他操作。

*整体示例：*

  代码：
  ```cpp
  SRBK_Choice("帮助老人/无视离开/", "");
  ```
  显示效果：
  ```text
  1. 帮助老人
  2. 无视离开
  按下对应数字键选择
  ```
  若选择1：
  ```text
  选择编码(SRBK_variable_Selectencoding) = "1"
  单次选择编码(SRBK_variable_Selectencoding_Single) = "1"
  ```

  代码：
  ```cpp
  SRBK_Choice("红茶/咖啡/果汁/", "notappend");
  ```
  显示效果：
  ```text
   1. 红茶
   2. 咖啡
   3. 果汁
  按下对应数字键选择
  ```
  若选择2：
  ```text
  选择编码(SRBK_variable_Selectencoding) = "1"  // 保持不变
  单次选择编码(SRBK_variable_Selectencoding_Single) = "2"
  ```

  代码：
  ```cpp
  // 连续选择示例
  SRBK_Choice("攻击/防御/", "");
  SRBK_Choice("追击/撤退/", "");
  SRBK_Choice("治疗/休息/", "notappend");
  ```
  若依次选择1、2、1：
  ```text
  选择编码(SRBK_variable_Selectencoding) = "12"
  单次选择编码(SRBK_variable_Selectencoding_Single) = "1"
  ```
*使用场景说明：*

  使用空字符串""：适用于主线剧情的关键选择，这些选择会影响游戏结局和剧情走向

  使用"notappend"：适用于日常对话、服装选择、不影响主线的次要选择等

**编译代码**：

*环境检查*

该程序***仅能***在Windows环境下运行，测试时所使用的Windows版本如下，不保证对其他版本及系统的兼容性
```
Microsoft Windows 11 专业版
版本21H2（OS内部版本 22000.2538）
```
确保计算机上拥有GCC编译器，测试时所使用的编译器版本信息如下，不保证对其他版本及编译器的兼容性
```
g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 7.3.0
```
*编译代码*

使用以下命令编译代码：
``` 
g++ main.cpp -o main.exe -I ./src
```
**运行项目**

*运行程序*

运行编译后的可执行文件：
```
./main.exe
```
*控制对话*

- 按下空格键、回车键或鼠标左键可以跳过逐字输出，直接显示完整对话，或开始下一个对话
- 按下“A”键或F6键可以开启或关闭自动对话模式
- 按下Ctrl键可以快速播放
- 显示选择支时，按下数字键1-9可选择对应选项
  
## 注意事项

- 该程序***仅能***在Windows环境下运行，使用了Windows API来检测按键状态。
- 请***不要删除***`main.cpp`的`main()`函数中的首行代码：
    ``` cpp
    system("chcp 65001");
    ```
    否则会导致输出乱码。
## 贡献
 
我们非常非常欢迎任何贡献！

并且我是一名高一学生...这是我的第一个开源项目，如果有人愿意帮忙改改我的屎山代码，那真是万分感谢！！

如果您有任何想法或贡献，麻烦按照以下步骤进行贡献，太谢谢了：
 
1. Fork 该仓库
2. 创建新的分支（`git checkout -b feature-branch`）
3. 提交你的修改（`git commit -am 'Add new feature'`）
4. 推送到远程仓库（`git push origin feature-branch`）
5. 创建 Pull Request

## 许可证
该项目遵循2-Clause BSD许可证。有关详细信息，请参阅LICENSE文件。

## 结语
这是我在Github发布的第一个项目！十分感谢能看到这里！

特别鸣谢：澄