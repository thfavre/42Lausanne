<p align="center">
<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Liberation+Mono&size=38&duration=5000&pause=4000&center=true&vCenter=true&width=435&lines=42Lausanne" alt="Typing SVG 42Lausanne" /></a>
</p>

<p align="center">
My <a href="https://github.com/diabolo257/42Lausanne/tree/main/42Piscine">Piscine</a> and <a href="https://github.com/diabolo257/42Lausanne/tree/main/42Cursus">Cursus</a> at 42 Lausanne.
</p>
<br>


## <img src="https://media.giphy.com/media/iY8CRBdQXODJSCERIr/giphy.gif" width="35"><b> Github Stats </b>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/repo-size/diabolo257/42Lausanne?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/diabolo257/42Lausanne?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/diabolo257/42Lausanne?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/diabolo257/42Lausanne?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/diabolo257/42Lausanne?color=brightgreen" /><br>
</p>

## Strange
### 1) Designated Initializers
```C
int a[6] = { [4] = 29, [2] = 15 };
// Is the same as 
int a[6] = { 0, 0, 15, 0, 29, 0 };
```
### 2)
```C
lst[i];
// Is the same as
i[lst];
```
Why? Because `lst[i]` means `*(lst+i)`

### 3) goto
```C
label:
...
goto label;
```

### 4) fast swap
```C
a ^= b ;
b ^= a;
a ^= b;
```

### 5) any-order structure initialization
```C
struct foo{
  int x;
  char* name;
};

void main(){
  struct foo f = { .name = "awesome", .x = -38 };
}

```
