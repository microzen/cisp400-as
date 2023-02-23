# Classes

## Initialize List

```c++
class Test{
public:
    Test(int x,int y);
private:
    int i,k;
};

Test::TestTest(int x,int y):i(x),k(y){
    
}
```

[See More](../tst/InitializeList.cpp)

---

# Universal and Uniform Initialize Syntax

`C++ 11`:

```c++
int squares[] {1, 3, 4, 5};
Test t {1};
int i = sun({1,2,3});
```