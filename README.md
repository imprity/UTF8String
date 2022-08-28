# Smple UTF8 String Library

Very Simple *(and probably unsafe)* c string libray.

Just include it in your code and build with it.

- Exmaple
```
UTFString* str = utf_str_from_cstr(u8"Hello World");
UTFStringView sv = utf_sv_from_str(str);

UTFStringView hello = utf_sv_sub_sv(sv, 0, 5);
UTFStringView world = utf_sv_sub_sv(sv, 6, sv.count);

//Do some kewl things with it
```