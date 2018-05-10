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