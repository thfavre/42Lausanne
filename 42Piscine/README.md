# 42Piscine

Piscine at 42 Lausanne September 2022


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
