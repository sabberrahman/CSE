![[Pasted image 20250309215326.png]]
![[Pasted image 20250309215340.png]]
![[Pasted image 20250309215443.png]]


![[Pasted image 20250309215737.png]]

![[Pasted image 20250309215910.png]]



![[Pasted image 20250309220727.png]]



```js
class JAvascript {
constractor(name,slug){
this.name= name
this.slugVAR = slug
}
}

class Roadmap {
  constructor(name, description, slug) {
    this.name = name;
    this.description = description;
    this.slug = slug;
  }

  getRoadmapUrl() {
    console.log(`https://roadmap.sh/${this.slug}`);
  }
}

class JavaScript extends Roadmap {
  constructor(name, description, slug) {
    super(name, description, slug);
  }

  greet() {
    console.log(`${this.name} - ${this.description}`);
  }
}

const js = new JavaScript(
  'JavaScript Roadmap',
  'Learn JavaScript',
  'javascript'
);

js.getRoadmapUrl(); // https://roadmap.sh/javascript
js.greet(); // JavaScript Roadmap - Learn JavaScript
```

![[Pasted image 20250309221400.png]]


There are serveral ways to find unique values in an array. Here are some of them:

## Using `Set`

```js
const roadmaps = ['JavaScript', 'React', 'Node.js', 'Node.js', 'JavaScript'];
const uniqueRoadmaps = [...new Set(roadmaps)];
console.log(uniqueRoadmaps); // ['JavaScript', 'React', 'Node.js']
```

## Using `filter()`

```js
const roadmaps = ['JavaScript', 'React', 'Node.js', 'Node.js', 'JavaScript'];
const uniqueRoadmaps = roadmaps.filter(
  (roadmap, index) => roadmaps.indexOf(roadmap) === index
);
console.log(uniqueRoadmaps); // ['JavaScript', 'React', 'Node.js']
```

## Using `reduce()`

```js
const roadmaps = ['JavaScript', 'React', 'Node.js', 'Node.js', 'JavaScript'];
const uniqueRoadmaps = roadmaps.reduce((unique, roadmap) => {
  return unique.includes(roadmap) ? unique : [...unique, roadmap];
}, []);
console.log(uniqueRoadmaps); // ['JavaScript', 'React', 'Node.js']
```

## Using `forEach()`

```js
const roadmaps = ['JavaScript', 'React', 'Node.js', 'Node.js', 'JavaScript'];
const uniqueRoadmaps = [];
roadmaps.forEach((roadmap) => {
  if (!uniqueRoadmaps.includes(roadmap)) {
    uniqueRoadmaps.push(roadmap);
  }
});
console.log(uniqueRoadmaps); // ['JavaScript', 'React', 'Node.js']
```

## Using `for...of`

```js
const roadmaps = ['JavaScript', 'React', 'Node.js', 'Node.js', 'JavaScript'];
const uniqueRoadmaps = [];
for (const roadmap of roadmaps) {
  if (!uniqueRoadmaps.includes(roadmap)) {
    uniqueRoadmaps.push(roadmap);
  }
}
console.log(uniqueRoadmaps); // ['JavaScript', 'React', 'Node.js']
```



![[Pasted image 20250309222240.png]]



Hoisting is a JavaScript mechanism where variables and function declarations are moved to the top of their scope before code execution. This means that no matter where the functions and variables are declared, they are moved to the top of their scope regardless of whether their scope is global or local. Note that hoisting only moves the declaration, not the initialization.

```js
console.log(x === undefined); // true
var x = 3;
console.log(x); // 3
```

The above code snippet can be visualized in the following way:

```js
var x;
console.log(x === undefined); // true
x = 3;
console.log(x); // 3
```

To make an object immutable, you can use `Object.freeze()` method. It prevents the modification of existing property values and prevents the addition of new properties.

```js
const roadmap = {
  name: 'JavaScript',
};

Object.freeze(roadmap);

roadmap.name = 'JavaScript Roadmap'; // throws an error in strict mode
console.log(roadmap.name); // JavaScript
```



![[Pasted image 20250311001917.png]]

setInterval -> infiity time 
setTimeout -- only once

## Pre-increment

The pre-increment operator increases the value of a variable by 1 and then returns the value. For example:

```js
let x = 1;
console.log(++x); // 2
console.log(x); // 2
```

## Post-increment

The post-increment operator returns the value of a variable and then increases the value by 1. For example:

```js
let x = 1;
console.log(x++); // 1
console.log(x); // 2
```


## Using the rest parameter:

The rest parameter allows you to represent an indefinite number of arguments as an array.

```js
function displayArgs(...args) {
  args.forEach((arg) => console.log(arg));
}
displayArgs(1, 2, 3, 4); // Outputs: 1, 2, 3, 4
```

The rest parameter (`...args` in the example) is generally more modern and flexible, and it provides an actual array, unlike the array-like `arguments` object.



------------
Javascript Interview questuin -- piush grag



![[Pasted image 20250313232600.png]]

![[Pasted image 20250313232722.png]]




tempural dead zone -- var chole but let chole na

![[Pasted image 20250313233759.png]]

![[Pasted image 20250313234232.png]]



![[Pasted image 20250313234906.png]]

30
100 ANSWAR


----------------------------------
![[Pasted image 20250314195511.png]]

### **How to Copy Objects Without Reference**

If you want to **create a new object instead of copying the reference**, you need to **clone** it:

#### **Shallow Copy (One Level Deep)**

- Using **spread operator** `{ ...obj }`:
    
    js
    
    CopyEdit
    
    `let obj1 = { name: "Alice" }; let obj2 = { ...obj1 }; obj2.name = "Bob";  console.log(obj1.name); // "Alice" (unchanged) console.log(obj2.name); // "Bob"`


- **Primitives are copied by value** (independent copies).
- **Objects are copied by reference** (changes affect both variables).
- To prevent unintentional modification, **clone objects properly** using `structuredClone()`, spread (`{ ...obj }`), or `Object.assign()`.



```ts

const name = 'JavaScript'; // Stored on the stack
const roadmap = { name: 'JS' }; // `roadmap` reference on the stack, actual object { name: 'JS' } in the heap
```

## **Heap Memory (Reference Data)**

The **Heap** is an **unstructured memory** area where **objects and reference types** (arrays, functions, objects) are stored.

### **How it Works**

- **Objects** are stored in the **heap**, and variables hold **references (memory addresses) to them**.
- Unlike the stack, memory in the heap is **not automatically removed** when a function ends—it is managed by JavaScript’s **Garbage Collector**.

### **Example**


`let person = { name: "Alice", age: 25 }; // Stored in heap let anotherPerson = person; // Another reference to the same object  anotherPerson.age = 30;   console.log(person.age); // 30 (Both variables refer to the same object)`

- The object `{ name: "Alice", age: 25 }` is stored in the heap.
- `person` and `anotherPerson` **both hold references** to the same object, so changes affect both.

![[Pasted image 20250314201204.png]]

![[Pasted image 20250314201425.png]]

The Nullish Coalescing Operator (`??`) returns the right operand if the left one is `null` or `undefined`, otherwise, it returns the left operand. It's useful for setting default values without considering falsy values like `0` or `''` as absent.

```js
console.log(null ?? 'hello'); // hello
console.log(undefined ?? 'hello'); // hello
console.log('' ?? 'hello'); // ''
console.log(0 ?? 'hello'); // 0
```

There are four logical operators in JavaScript: `||` (OR), `&&` (AND), `!` (NOT), and `??` (Nullish Coalescing). They can be used with boolean values, or with non-boolean values.

## OR (||)

The OR operator (`||`) returns the first truthy value, or the last value if none are truthy.

```js
console.log('hello' || 0); // hello
console.log(false || 'hello'); // hello
console.log('hello' || 'world'); // hello
```

## AND (&&)

The AND operator (`&&`) aka logical conjunction returns the first falsy value, or the last value if none are falsy.

```js
console.log('hello' && 0); // 0
console.log(false && 'hello'); // false
console.log('hello' && 'world'); // world
```

## NOT (!)

It simply inverts the boolean value of its operand.

```js
console.log(!true); // false
console.log(!false); // true
console.log(!'hello'); // false
console.log(!0); // true
```

## Nullish Coalescing (??)

The Nullish Coalescing Operator (`??`) returns the right operand if the left one is `null` or `undefined`, otherwise, it returns the left operand. It's useful for setting default values without considering falsy values like `0` or `''` as absent.

```js
console.log(null ?? 'hello'); // hello
console.log(undefined ?? 'hello'); // hello
console.log('' ?? 'hello'); // ''
console.log(0 ?? 'hello'); // 0
```

- **It evaluates from left to right**.
- **Stops at the first falsy value** (Short-circuiting).
- **If all values are truthy, the last value is returned**.

---

## **1. Returning the First Falsy Value**



`console.log(0 && "Hello");         // 0 (falsy) console.log("" && "World");        // "" (falsy) console.log(null && "JavaScript"); // null (falsy) console.log(false && 42);          // false (falsy) console.log(undefined && "test");  // undefined (falsy)`

👉 **Stops at the first falsy value and returns it.**  
👉 The remaining expressions are **not evaluated** (Short-circuiting).

---

## **2. Returning the Last Value if All Are Truthy**



`console.log(5 && "Hello");       // "Hello" (last value) console.log(true && 10 && "OK"); // "OK" (last value) console.log(1 && "JS" && 99);    // 99 (last value)`

👉 **Since all values are truthy, the last value is returned.**

![[Pasted image 20250314203416.png]]

![[Pasted image 20250314203427.png]]

## querySelector

The `querySelector` method returns the first element that matches the specified selector. If no matches are found, it returns `null`.

```js
const roadmapWrapper = document.querySelector('.roadmap-wrapper');
const roadmapTitle = document.querySelector('#roadmap-title');
```

## querySelectorAll

The `querySelectorAll` method returns a `NodeList` of all elements that match the specified selector. If no matches are found, it returns an empty `NodeList`.

```js
const roadmapItems = document.querySelectorAll('.roadmap-item');
```

### **Why `querySelectorAll()` Might Not Be the Best Choice**

`querySelectorAll()` **isn't necessarily "bad,"** but it has a key limitation:  
❗ **It returns a `NodeList`, which is static (not live).**

This means that if elements are **added or removed dynamically**, the `NodeList` will **not update automatically**.


## **🔴 Problem: `querySelectorAll()` Returns a Static List**

Let's see an example where `querySelectorAll()` doesn't reflect new elements:


`// Get all paragraphs let paragraphs = document.querySelectorAll("p"); console.log(paragraphs.length); // Suppose we have 3 <p> elements  // Add a new paragraph dynamically let newPara = document.createElement("p"); newPara.textContent = "New paragraph"; document.body.appendChild(newPara);  // Check paragraph count again console.log(paragraphs.length); // Still 3 (even though a new <p> was added)`

👉 The `NodeList` returned by `querySelectorAll()` **does not update** after the new `<p>` is added.


```js
const div = document.createElement('div');

div.id = 'roadmap-wrapper';
div.setAttribute('data-id', 'javascript');
console.log(div); // <div id="roadmap-wrapper" data-id="javascript"></div>
```


```js
const roadmapWrapper = document.querySelector('.roadmap-wrapper');

const roadmap = document.createElement('div');
roadmap.id = 'javascript-roadmap';

const roadmapTitle = document.querySelector('#roadmap-title');
roadmapWrapper.insertBefore(roadmap, roadmapTitle);
```



In order to scroll to the top of the page, we can use the `scrollTo` method.

```js
window.scrollTo(0, 0);
```


You can use `getBoundingClientRect` method to get the dimensions of an element.

```js
const roadmapWrapper = document.querySelector('.roadmap-wrapper');
const dimensions = roadmapWrapper.getBoundingClientRect();

console.log(dimensions); // DOMRect { x: 8, y: 8, width: 784, height: 784, top
```

















































































































































































