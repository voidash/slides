// Boolean
let isDone: boolean = false;

// Number
let decimal: number = 6;
let hex: number = 0xf00d;
let binary: number = 0b1010;
let octal: number = 0o744;

// String
let color: string = "blue";
let fullName: string = `John Doe`;
let sentence: string = `Hello, my name is ${fullName}.`;

// Array
let list: number[] = [1, 2, 3];
let anotherList: Array<number> = [4, 5, 6];

// Tuple
let tuple: [string, number] = ["hello", 10];

// Enum
enum Color {
  Red,
  Green,
  Blue,
}
let c: Color = Color.Green;

// Any
let notSure: any = 4;
notSure = "maybe a string instead";
notSure = false;

// Void
function logMessage(): void {
  console.log("This function doesn't return anything");
}

// Null and Undefined
let u: undefined = undefined;
let n: null = null;

// Never
function throwError(message: string): never {
  throw new Error(message);
}

// Object
let obj: object = {
  name: "John Doe",
  age: 30,
};
