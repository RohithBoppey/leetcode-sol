OOPS would have 4 pillars: 

- Encapsulation
- Polymorphism
- Abstraction
- Inhertitance

---

## What are Interfaces and Abstract Classes? 
- Interface defines the input and output of the thing. Describes the structure that the application must follow. The idea is to expose functionality. 
- Ex: Having a water boiler - we know that water boiler should have an inlet for cold water, a button to start the machine, and outlet for the warm water. Or else a TV, I have a remote to change the TV channel, but if otherwise, I should know the inner working of TV to change the channel. **User should not know about the TV - this is a black box**
- Interface is the logical layer between user and the application. User knows how to use, but doesn't know the insides of the application. Interface is the TV remote, Implemenation is TV and Consumer is user.
- ![image](https://github.com/user-attachments/assets/bc703d25-8c18-4982-be7f-a530e35eb7b6)
- Rabbit - Prey, Hawk - Predator and Fish is both. Here Prey and Predator are Interfaces.
- Every water boiler **must** have these 3 things, but their implementation can be different.
- **Interfaces only explain input, output of the class, but not the underlying implementation**
- Abstract classes also give you the implemenation as well. In the same water boiling example, an abstract class would also provide on how the water is boiled. Regular classes can inherit the water boiling method themselves.

![image](https://github.com/user-attachments/assets/9da80451-bd4e-4586-894c-c39c3b0094af)

1. I can read the variable properties from a variable name I declared. So for using the variable string, I would require the name and the type.
2. Similarly to 1. for using the entire object, I would require name and type.
3. For using a function, I would require the __inputs for function, function name, type and return types__. I can keep using this function without knowing the underlying implementation of it as long as I know the input types, and output types. 

### Consumer vs Implementation 
![image](https://github.com/user-attachments/assets/f6bda3c7-66ee-4b68-b0e2-89dfc40708e4)
