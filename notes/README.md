# 笔记

> ***完完全全的个人理解，可能有误漏，仅供参考***
>
> 编辑工具：Typora

***



## HTML5

```html
实体格式：
	&实体名; 
	如&lt;(<) &gt;(>) &nbsp;(不换行空格) &copy;(copyright)
    
编码：
     使用<meta/>标签指定网页编码，浏览器解析网页时会使用指定编码解析。
         格式:
         <meta charset="utf-8"/>
        
自结束标签：
        <br/>换行
        <hr/>水平线
        <meta /> 元标签
        
img标签：
        img是一个自结束标签。
        属性：
        	src，指定要显示的图片的URL
        	alt，在图片无法显示时，显示的文字描述
        	width、height，图片宽高，一般用px（像素）作为单位
        <img src="1.gif" alt="图片1"/>
        
内联框架：
        使用iframe标签引入一个内联框架
        
跳转到页面中指定位置：
        <a href="#[元素id]"></a>

加载外部样式表的固定写法:
		<link rel="stylesheet" type="text/css" href=""/>

       
CSS清除列表样式：list-style:none;
CSS设置横向列表: li{display:inline;}    
盒子模型：由内边距、外边距、边框组成        
```



## JavaScript

### JS prototype

```javascript
//构造函数，返回的是一个对象，会执行函数体内的代码块
function Person(name,age){
    //此处的this指实例化Person的对象
    this.name = name;
    this.age = age;
}

//将toString()方法复写
Person.prototype.toString = function(){
    return this.name+","+this.age;
}

p1 = new Person("Bob",13);
console.log(p1); // "Bob,13"
```

### JS 数据类型

```javascript
Nubmer
String
Boolean
undefine
Function
```

### 工厂方法生成对象

```javascript
//方法
function createPerson(name,age){
    return {name:name,age:age};
}

var p1 = createPerson("Jack",11);

```




## Java

### 集合框架

```java
interface Collection
    interface List
           		 class LinkedList //增删快，访问慢
            	 class ArrayList //访问快，增删慢
    interface Set
    	class HashSet //元素唯一，不保证顺序
    	class LinkedSet //同上，保证顺序
   	interface Map
    	class HashMap //包含键值对(K,V) ， 键唯一
    	class TreeMap //底层为红黑树，会对值进行排序
```

### 数据类型

> Java的两大数据类型：
>
> 基本类型(8个)：byte、short、char、int、long、float、double、boolean
>
> * 类型提升：int前的类型在参与运算时会提升为int类型，要注意类型转换。
>
> 引用类型：除基本类型外的所有类型。
>
> * 引用类型就像被封装的指针。new 出来的对象都存在堆中，由Java垃圾回收器管理。

## C

### 关于内存的一些笔记

> 自动变量：生命周期从函数开始，到函数结束，存在栈内存中。
>
> 静态变量：生命周期从定义开始，到程序结束。分配在堆内存中。
>
> 全局变量：同静态变量，访问域为全局。
>
> **通过malloc等函数分配的内存：**
>
> **内存占用从分配开始，到free释放结束。分配的内存在堆内存中，若使用完后没有得到释放，则会发生内存泄漏。**
>
> **发生内存泄漏可能情况：丢失指向内存的指针、没有free malloc分配的对应的内存区域等**。
>
> ~~*要小心内存泄漏哦*~~
>
> **字符串常量池：**
>
> 直接将字符串常量赋值给字符指针，赋值的字符串常量将会存在字符串常量池内，这部分内存通常是只读的，且多个相同的字符串常量存在于是同一个地址（仅有一个副本）。比如char * s = "string";s指向"string"的字符串常量池地址。

## 算法

### 中缀表达式计算求值
>1. *分别用**数字栈**和**操作符栈**保存数字及操作符。*
>2. 碰到数字入数字栈，碰到操作符分情况讨论:
>   * 若操作符栈为空或当前操作符为'(' 则操作符直接入栈，否则比较当前操作符和栈顶操作符的优先级
>     
>     * **若当前操作符的优先级大于栈顶操作符或不为')'，则直接入栈，否则循环出栈操作符栈进行**计算**，直到当前操作符优先级大于栈顶操作符或当前操作符为'('。**
>     
>   * 操作符入栈
>   
>   * ***运算部分：数字栈出栈两个元素a、b，按b 运算符 a的顺序进行计算，将计算结果存入数字栈***。
>   
>3. 无数字入栈后若操作符栈不为空，则循环出栈操作符栈进行运算，直到操作符栈为空。此处不考虑运算优先级问题，操作和运算部分相同。


### 回溯算法（backtrack）

>回溯算法实际上一个类似枚举的搜索尝试过程，主要是在搜索尝试过程中寻找问题的解，当发现已不满足求解条件时，就 “回溯” 返回，尝试别的路径。回溯法是一种选优搜索法，按选优条件向前搜索，以达到目标。但当探索到某一步时，发现原先选择并不优或达不到目标，就退回一步重新选择，这种走不通就退回再走的技术为回溯法，而满足回溯条件的某个状态的点称为 “回溯点”。许多复杂的，规模较大的问题都可以使用回溯法，有“通用解题方法”的美称。
>
>回溯算法的基本思想是：从一条路往前走，能进则进，不能进则退回来，换一条路再试。
>
>链接：https://leetcode-cn.com/tag/backtracking/
>来源：力扣（LeetCode）

#### 基本格式

```java
List<String> list = new LinkedList<>();
List<List<String>> res = new ArrayList<List<String>>();

public void backtrack(int step,int n){
    //当条件满足时，添加一个解并回溯到上一层
	if(list.size() == n){
        res.add(list);
        return;
    }
    
    for(int i=起始步数;i<终止步数;i++){
        list.add(i); //添加一个可能的解元素
        backtrack(step + 1,n); //递归求解
        list.removeLast(); //移除最后一个元素
    }
}
```

#### 例子

##### [组合总和](https://leetcode-cn.com/problems/combination-sum/)

```java
class Main{
    public static LinkedList<Integer> list = new LinkedList<>();
    public static List<List<Integer>> ans = new LinkedList<List<Integer>>();

    public static void backtrack(int[] arr,int target,int sum,int step){
        if(sum > target){ //若组合总和大于目标值，结束本层递归
            return;
        }

        if(sum == target){ //找到一个解
            ans.add(new LinkedList<Integer>(list));
            return;
        }

        for(int i=step;i<arr.length;i++){ //从第step步开始寻找可行解，去除重复解
            list.add(arr[i]); //添加一个可能的解元素
            backtrack(arr,target,sum+arr[i],i); //递归求解
            list.removeLast(); //移除最后一个元素
        }
    }
    
    public static void main(String[] args){
        int[] arr = {1,2,3};
        backtrack(arr,7,0,0);
    }
}
```

##### [全排列](https://leetcode-cn.com/problems/permutations/)

```java
public class Permutations {

	static LinkedList<Integer> list = new LinkedList<>();
	static List<List<Integer>> ans = new ArrayList<List<Integer>>();
	static boolean[] vis = new boolean[9]; //标记元素是否被访问
	
	public static void main(String[] args) {
		int[] nums = {1,2,3};
		backtrack(nums,0);
	}
	
	public static void backtrack(int[] nums,int step) {
		if(step == nums.length) { //找到一个解
			ans.add(new LinkedList<>(list)); //将解添加至答案列表
			return;
		}
		
		for(int i=0;i<nums.length;i++) {
			if(!vis[i]) { //若当前元素未被使用
				list.add(nums[i]); //添加元素
				vis[i] = true; //标记当前元素已被使用
				backtrack(nums,step+1); //进入下一层递归
				vis[i] = false; //当找到一个解后，标记当前元素未被使用
				list.removeLast(); //移除最后一个元素
			}
		}
	}
}
```

### 喜闻乐见双指针

> 目前见到的双指针问题只要弄清楚”哨兵“的位置就行了，可以参考快排中使用的循环的思想

#### 反转字符串

```c
#include <stdio.h>

void reverseString(char *string){
    int i=0,j = strlen(string)-1;
    char temp;
    
    while(i<j){
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++,j--;
    }
}

int main(void){
    //若使用char * str = "12345";格式，则字符串会被当成字符串常量存储
    char str[6] = "12345";
	reverseString(str);
    puts(str); //54321
    return 0;
}
```

#### [反转字符串中的元音字母]( https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)

```java
public class ReverseVowels {
	public static void main(String[] args) {
		System.out.println(reverseVowels("leetcode"));
	}

	public static String reverseVowels(String s) {
		int begin = 0, end = s.length() - 1;
		char[] res = s.toCharArray();
		List<Character> vowels = new ArrayList<>();
		
		"aeiouAEIOU".chars().forEach(c -> vowels.add((char) c));

		while (begin < end) {
			while (!vowels.contains(s.charAt(begin)) && begin < end)
				begin++;
			while (!vowels.contains(s.charAt(end)) && begin < end)
				end--;
			
			char temp = res[begin];
			res[begin] = res[end];
			res[end] = temp;
			begin++;end--;
		}
		
		return new String(res);
	}
}
```



