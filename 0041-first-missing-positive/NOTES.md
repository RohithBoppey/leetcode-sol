​ASKED IN **META**: 

FIRST MISSING POSITIVE INTEGER ✅
EXPECTED CONSTAINTS - TC: O(N) ; SC: O(1) // MEANING NO EXTRA SPACE 

FEW OBSERVATIONS:   
1.    
![image](https://gist.github.com/assets/73538974/aea65074-aecf-44df-83ed-998f09239676)    
-> SO IF THERE ARE NEGATIVE NUMBERS, WE NEED NOT DO ANYTHING, JUST IGNORE   
    
2.    
![image](https://gist.github.com/assets/73538974/ec9dfba0-0c9a-45c5-a3b9-9b4ed4bf05a8)    
IF ALL ARE POSITIVES, THEN THE NUMBERING STARTS FROM [1,2,3,4,...] SO ON    
    
SIMPLE INTUITION:   
**USING O(N) SPACE**:     
![image](https://gist.github.com/assets/73538974/b0bf6922-9e20-4566-b345-02f850ab9d91)    
JUST MARKING WHICH NUMBERS ARE PRESENT IN ONE LOOP => AND IN SECOND LOOP - WE CAN FIND WHERE THE FIRST FALSE IS AT -> RETURN THAT index   
    
```
code
```
      
ONE THING WE CAN UNDERSTAND IS THAT - [1,2,3,...N] => WHATEVER IS FIRST MISSING, WE NEED TO RETURN THAT!

PATTERN IS THERE IT SEEMS..... => `USING NUMBER AS index` => 
