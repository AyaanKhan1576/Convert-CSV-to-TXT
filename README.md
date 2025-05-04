---

# CSV to TXT Converter  

## Description  
This program converts a CSV file into a TXT file, formatting each row so that the first value (node) is followed by its associated values, separated by commas.  

## Usage  
```bash
./csv_to_txt input.csv output.txt
```  

## Compilation  
```bash
gcc csv_to_txt.c -o csv_to_txt
```  

## Example  
### **Input (input.csv)**  
```
1,2,3,4  
5,6,7  
8,9  
```  
### **Output (output.txt)**  
```
1:2,3,4  
5:6,7  
8:9  
```  

## Notes  
- The program takes two arguments: the input CSV file and the output TXT file.  
- It handles basic CSV structures but assumes values are separated by commas.  
- Ensure the input file exists before running the program.  

