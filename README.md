---

# Unicode-To-UTF-8 

---
``This project demonstrates how to convert Unicode code points into their corresponding UTF-8 hexadecimal escape sequences using C++. The program can process an array of Unicode code points 
and convert each one to UTF-8.``

## Introduction
This C++ program takes Unicode code points (such as `U+1F600`) and converts them into their corresponding UTF-8 hexadecimal escape sequences. UTF-8 is one of the most commonly used character encodings for web and text data, allowing for compact representation of characters from many languages, including emojis.

The code supports processing multiple Unicode code points through an array, making it flexible for handling various inputs.

## Unicode and UTF-8

### Unicode
Unicode is a standard designed to represent text from all the world's writing systems. Every character is assigned a unique code point, typically expressed in hexadecimal form. For example, the Unicode code point for the emoji 😀 is `U+1F600`.

### UTF-8
UTF-8 is a variable-length character encoding used for encoding Unicode characters. It uses 1 to 4 bytes to represent characters, depending on the code point. UTF-8 is widely used because of its backward compatibility with ASCII and efficiency in encoding.
