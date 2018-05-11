# AC DataTypes Plus #

this repo is a fork of mentor's  Algorithmic C Datatype providing more feature and Eigen library compatibility.

## TODO : ##

Everything!


## changes ##

* add width to ac_datatype
* ac_base_type become base class of ac_int,ac_fixed,ac_float,ac_channel,ac_complex
* add is_ac_type to detect a type is an ac_type
* add is_ac_basic_type to detect a class is ac_int,ac_fixed or ac_channel,ac_complex of these two types
* add ac_hex_string ac_hex_wstring ac_hex_u16string ac_hex_u32string
* add ac_bin_string ac_bin_wstring ac_bin_u16string ac_bin_u32string (any of these strings can convert to ac_basic_type directly. any of these string can be convert from ac_base_type directly )
* add _bin _hex literal to 4 types of strings
* add math lib porting
* support eigen

## examples ##

### ac_bin_string ###

```c++
auto bin_str = "1001_0110_b"_bin;//'-','_','b',' ' would be ignored
ac_int<8,false> data = bin_str;

cout << bin_str << endl;
cout << data << endl;

data = 42;
bin_str = data;

cout << bin_str << endl;
cout << data << endl;
```


### ac_hex_string ###

```c++
auto bin_str = "0x55AA"_hex;//'-','_',' ','h','H',"0x" would be ignored
ac_int<16,false> data = bin_str;

cout << bin_str << endl;
cout << data << endl;

data = 42;
bin_str = data;

cout << bin_str << endl;
cout << data << endl;
```

### ac_convert ###

```c++
auto ac_int<16,false> data;
auto bits = ac_convert::to_bitset(data);

cout << data << endl << bits << endl;
```

### ac_math ###

```c++
auto ac_fixed<16,1,true> data = 0.5;

cout << sqrt(data) << endl;
```

### type detect ###

```c++
cout << is_ac_type<int8>::value << endl;   // true
cout << is_ac_type<ac_float<16,1,8>>::value << endl; // true
cout << is_ac_type<int8_t>::value << endl; // false
cout << is_ac_type<ac_channel<int>>::value << endl; // true
cout << is_ac_type<ac_channel<int8_t>>::value << endl; // true


cout << is_ac_basic_type<int8>::value << endl; // true
cout << is_ac_basic_type<int8_t>::value << endl; // false
cout << is_ac_basic_type<ac_float<16,1,8>>::value << endl; // false
cout << is_ac_basic_type<ac_channel<int8>>::value << endl; // true
cout << is_ac_basic_type<ac_channel<int8_t>>::value << endl; // false
```