---
paginate: true
marp: true
math: mathjax
---

# Programming Fundamentals

---

# Agenda

- Introduction to Computer Programming
- Programming Concepts
  - Primitive Types
  - Syntax And Structure
  - Control Structures: Loop, if-else
- Hands-on Programming Activity
  - Learning to set up Arduino IDE
  - Writing Simple Program
    - Hello World
    - BMI Calculator

---

# Introduction to Computer Programming

---

# Programming Languages

Programming languages are tools that enable humans to communicate instructions to computers. They come in various models or paradigms, each with its own approach to problem-solving.

---

# Types of Programming Languages

1. **Procedural Languages**
   - Emphasize procedures or functions.
   - Examples: C, Pascal.

2. **Object-Oriented Languages**
   - Organize code into objects.
   - Examples: Java, Python.

3. **Functional Languages**
   - Treat computation as mathematical functions.
   - Examples: Haskell, Lisp.

4. **Scripting Languages**
   - Interpreted languages for scripting tasks.
   - Examples: JavaScript, Python.

5. **Markup Languages**
   - Define and describe structured data.
   - Examples: HTML, XML.

<style scoped>
    * {
        font-size:10px:
    }
</style>


---

# Choosing the Right Language

- The choice of programming language and paradigm depends on:
  - The problem you're solving.
  - Your programming goals and preferences.
  - The specific requirements of the project.

- Learning multiple languages and paradigms can make you a more versatile programmer.

---

## Programming Concepts

- Primitive Types
- Syntax And Structure
- Control Structures: Loop, if-else

---

### Primitive Types

- Definition of primitive types.
- Examples: `int`, `float`, `char`, `boolean`.
- How to declare variables of primitive types.

```cpp
int number = 42;
float temperature = 25.5;
char grade = 'A';
boolean isReady = true;
```

---

# Syntax And Structure

What is syntax in programming?
Importance of proper code structure.
Common syntax rules.

```
// Example of proper syntax and structure
void setup() {
  Serial.begin(9600);
}

void loop() {
  // Your code here
}
```
---

# Control Structures: Loop

- What is a loop?
- Types of loops: for, while, do-while.

Example code for a simple loop:
```
void loop() {
  for (int i = 0; i < 5; i++) {
    Serial.print("Iteration: ");
    Serial.println(i);
    delay(1000); // Delay for 1 second
  }
}
```

---

# Control Structures: if-else

What is conditional branching?

```
int sensorValue = analogRead(A0);

if (sensorValue > 500) {
  Serial.println("Sensor value is high.");
} else {
  Serial.println("Sensor value is low.");
}
```

---

# Hands-on Programming Activity


```
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello, World!");
  delay(1000); // Delay for 1 second
}
```

---

# Writing BMI Calculator


```
void setup() {
  Serial.begin(9600);
}

void loop() {
  float weight, height;
  Serial.print("Enter your weight (kg): ");
  while (!Serial.available());
  weight = Serial.parseFloat();
  Serial.print("Enter your height (m): ");
  while (!Serial.available());
  height = Serial.parseFloat();

  float bmi = weight / (height * height);
  Serial.print("Your BMI is: ");
  Serial.println(bmi);
}
```

---



