//TODO : needs """VERY HEAVY""" heavy refactoring
//TODO : maybe cache actual character count

#ifndef UTFString_HEADER_GUARD
#define UTFString_HEADER_GUARD

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

void utf8_to_32(char* char_array, size_t array_size, uint32_t* ret_array, size_t* ret_array_size);
void utf16_to_32(uint16_t* char_array, size_t array_size, uint32_t* ret_array, size_t* ret_array_size);

void utf32_to_8(uint32_t* char_array, size_t array_size, uint8_t* ret_array, size_t* ret_array_size);
void utf32_to_16(uint32_t* char_array, size_t array_size, uint16_t* ret_array, size_t* ret_array_size);

void utf8_to_16(uint8_t* char_array, size_t array_size, uint16_t* ret_array, size_t* ret_array_size);
void utf16_to_8(uint16_t* char_array, size_t array_size, uint8_t* ret_array, size_t* ret_array_size);

typedef struct UTFString {
    char* data;
    size_t raw_size;
    size_t data_size; //does not include null terminated character
    size_t count;
}UTFString;

typedef struct UTFStringView {
    char* data;
    size_t data_size; //does not include null terminated character
    size_t count;
}UTFStringView;

size_t utf_count_to_byte(UTFString* str, size_t count);
size_t utf_byte_to_count(UTFString* str, size_t byte);

UTFString* utf_from_cstr(const char* str);
UTFString* utf_from_sv(UTFStringView sv);

UTFString* utf_sub_str(UTFString* str, size_t from, size_t to);
UTFString* utf_sub_sv(UTFStringView sv, size_t from, size_t to);
UTFString* utf_copy(UTFString* str);

void utf_destroy(UTFString* str);

size_t utf_count(UTFString* str);
size_t utf_count_left_from(UTFString* str, size_t from);
size_t utf_count_right_from(UTFString* str, size_t from);

size_t utf_next(UTFString* str, size_t pos);
size_t utf_prev(UTFString* str, size_t pos);

void utf_set_cstr(UTFString* str, const char* to_set);
void utf_set_str(UTFString* str, UTFString* to_set);
void utf_set_sv(UTFString* str, UTFStringView to_set);

void utf_append_cstr(UTFString* str, const char* to_append);
void utf_append_str(UTFString* str, UTFString* to_append);
void utf_append_sv(UTFString* str, UTFStringView to_append);


void utf_insert_cstr(UTFString* str, size_t at, const char* to_insert);
void utf_insert_str(UTFString* str, size_t at, UTFString* to_insert);
void utf_insert_sv(UTFString* str, size_t at, UTFStringView to_insert);

void utf_erase_range(UTFString* str, size_t from, size_t to);
void utf_erase_right(UTFString* str, size_t how_many);
void utf_erase_left(UTFString* str, size_t how_many);



size_t utf_sv_count_to_byte(UTFStringView sv, size_t index);
size_t utf_sv_byte_to_count(UTFStringView sv, size_t index);

UTFStringView utf_sv_from_cstr(const char * str);
UTFStringView utf_sv_from_str(UTFString* str);
UTFStringView utf_sv_sub_str(UTFString* str, size_t from, size_t to);
UTFStringView utf_sv_sub_sv(UTFStringView str, size_t from, size_t to);
UTFStringView utf_sv_copy(UTFStringView str);

size_t utf_sv_count(UTFStringView sv);
size_t utf_sv_count_left_from(UTFStringView sv, size_t from);
size_t utf_sv_count_right_from(UTFStringView sv, size_t from);

size_t utf_sv_next(UTFStringView sv, size_t pos);
size_t utf_sv_prev(UTFStringView sv, size_t pos);

UTFStringView utf_sv_trim_left(UTFStringView sv, size_t how_many);
UTFStringView utf_sv_trim_right(UTFStringView sv, size_t how_many);

bool utf_sv_cmp(UTFStringView str1, UTFStringView str2);

int utf_sv_find(UTFStringView str, UTFStringView to_find);
int utf_sv_find_last(UTFStringView str, UTFStringView to_find);
int utf_sv_find_left_from(UTFStringView str, UTFStringView to_find, size_t from);
int utf_sv_find_right_from(UTFStringView str, UTFStringView to_find, size_t from);

bool utf_sv_starts_with(UTFStringView sv, UTFStringView with);
bool utf_sv_ends_with(UTFStringView sv, UTFStringView with);

void utf_sv_fprint(UTFStringView sv, FILE* file);
void utf_sv_fprintln(UTFStringView sv, FILE* file);

bool utf_test();

#endif
