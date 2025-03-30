![[Pasted image 20250316205844.png]]


```html
<script>
  document.querySelector("sabber").addEventListener("click", function () {
    alert("You clicked the sabber tag!");
  });
</script>


<script>
  class SabberElement extends HTMLElement {
    connectedCallback() {
      this.innerHTML = "<strong>Sabber's Custom Tag!</strong>";
    }
  }

  customElements.define("sabber", SabberElement);
</script>

<sabber></sabber>

```


### **Unknown vs. Standard Elements**

- HTML is **forgiving**: If you create a tag like `<sabber>`, it won't break the page but will act as an inline element by default.
- Standard elements (like `<div>`, `<p>`, `<h1>`-`<h6>`) have predefined behavior.
- You can define new elements using **Web Components** (as shown earlier).


- **Block elements** (like `<div>`, `<p>`, `<h1>`, `<section>`) take up the full width of their container.
- **Inline elements** (like `<span>`, `<a>`, `<strong>`) only take up as much space as needed.
- Some elements are **inline-block**, meaning they behave like inline elements but can have width and height (e.g., `<button>`, `<img>`).

#### **HTML is Case-==Insensitive**==

- `<DIV>`, `<div>`, `<DiV>` all work the same in HTML.
- But in **XHTML** (older version of HTML that follows strict XML rules), tag names must be lowercase.


### **Self-Closing Tags**

- Some elements don’t need a closing tag, like `<img>`, `<input>`, `<br>`, and `<hr>`.
- In **XHTML or XML**, self-closing tags must have a `/`:
    
    html
    
    CopyEdit
    
    `<img src="image.jpg" />`
    
- In HTML5, `<img src="image.jpg">` works fine.

### **Custom Data Attributes (`data-*`)**

- HTML allows custom attributes starting with `data-`. Example:
    
    html
    
    CopyEdit
    
    `<button data-user-id="123">Click</button>`
    
- JavaScript can access it:
    
    js
    
    CopyEdit
    
    `let btn = document.querySelector("button"); console.log(btn.dataset.userId); // "123"`


- **Browsers automatically fix errors**  
    Example:
    
    html
    
    CopyEdit
    
    `<p>This is a paragraph <p>This is another paragraph`
    
    The browser **autocloses** the first `<p>`, rendering it like this:
    
    html
    
    CopyEdit
    
    `<p>This is a paragraph</p> <p>This is another paragraph</p>`


**Malformed tables get auto-fixed**

html

CopyEdit

`<table>   <td>Cell</td> </table>`

The browser adds `<tr>` automatically:

html

CopyEdit

`<table>   <tr><td>Cell</td></tr> </table>`


## **Render Blocking Behavior**

- **CSS is render-blocking**, meaning the page won’t load until CSS files are downloaded and applied.
- **JavaScript (without `async` or `defer`) blocks rendering**


```jsx
<script src="heavy.js"></script> <!-- Blocks HTML rendering -->

<script src="script.js" async></script>  <!-- Loads in parallel -->
<script src="script.js" defer></script>  <!-- Runs after HTML is parsed -->
--------------

<ul id="list">
  <li>Item 1</li>
  <li>Item 2</li>
</ul>

document.getElementById("list").addEventListener("click", function (event) {
  if (event.target.tagName === "LI") {
    alert("Clicked: " + event.target.textContent);
  }
});

------------------------





```


## **Content Visibility (`hidden`, `display: none`, `opacity: 0`, `visibility: hidden`)**

- **`hidden` attribute** – Removes from accessibility tree (better for SEO).
    
```html
`<p hidden>This won't be visible</p>`

```
    

- **`display: none;`** – Element disappears, **DOM space is removed**.
- **`visibility: hidden;`** – Element is **invisible but still takes space**.
- **`opacity: 0;`** – Element is **invisible but clickable**.


## **Lazy Loading Images (`loading="lazy"`)**

- Improves performance by loading images **only when visible**.


```html
`<img src="large-image.jpg" loading="lazy" alt="Lazy Loaded Image">`

```
    
    
## **`srcset` and `picture` for Responsive Images**

- Loads different images based on screen size.
    
    
    `<picture>   <source srcset="small.jpg" media="(max-width: 600px)">   <source srcset="medium.jpg" media="(max-width: 1200px)">   <img src="large.jpg" alt="Responsive Image"> </picture>`


## **Form Behavior & Enhancements**

### **7.1 Autofill & Autocomplete**

- Helps users fill forms quickly.
    
    
    `<input type="email" autocomplete="email"> <input type="name" autocomplete="name">`
    

### **7.2 `datalist` (Autocomplete without JavaScript)**

- Provides a dropdown of suggestions.
    
    
    `<input list="browsers"> <datalist id="browsers">   <option value="Chrome">   <option value="Firefox">   <option value="Edge"> </datalist>`


![[Pasted image 20250316213115.png]]

![[Pasted image 20250316213327.png]]


## **1. HTML 3.2 (1997) – The Early Stage**

**Key Features:**

- Introduced **tables**, **font tags**, and **basic scripting**.
- No CSS support (design was handled by `<font>` and `<center>` tags).
- Poor support for multimedia (images, but no video or audio).

```html

// html 3 
<center>
  <font color="red" size="5">Welcome to My Website!</font>
</center>

```

## **HTML 4.01 (1999) – Standardization & CSS Support**

**Key Features:**

- **Separation of content and design**: Moved styling from HTML to **CSS**.
- Introduced **`<div>` and `<span>`** for better structure.
- **Better form elements** (`<input type="text">`, `<textarea>`, etc.).
- Deprecated **non-semantic tags** like `<font>`, `<center>`, `<blink>`.
- Added **JavaScript support** (`<script>` tag inside `<head>`).

```html
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <title>My Website</title>
  <style>
    .highlight { color: blue; font-size: 20px; }
  </style>
</head>
<body>
  <div class="highlight">Hello, World!</div>
</body>
</html>

```

## **HTML5 (2014 - Present) – The Modern Standard**

**Key Features:** ✅ **Simplified Doctype**: No more complicated declarations.  
✅ **Native Audio & Video Support** (`<audio>`, `<video>`).  
✅ **New Semantic Elements** (`<header>`, `<nav>`, `<article>`, `<section>`).  
✅ **Improved Forms** (`<input type="email">`, `<input type="date">`).  
✅ **Canvas & SVG** for graphics.  
✅ **Web APIs** (Geolocation, WebSockets, WebRTC, LocalStorage).  
✅ **Mobile & Responsive Support** (Better with `<meta viewport>`).

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Modern HTML5</title>
</head>
<body>
  <header>
    <h1>Welcome to My Website</h1>
  </header>
  <section>
    <p>This is a modern HTML5 page.</p>
    <video controls>
      <source src="video.mp4" type="video/mp4">
      Your browser does not support the video tag.
    </video>
  </section>
</body>
</html>

```


---------------------

### **What is `<canvas>` in HTML?**

The `<canvas>` element in HTML5 is used to draw graphics, animations, and complex visual effects using JavaScript. It acts like a **blank slate** where you can programmatically draw shapes, images, and interactive elements.


### **Can You Make Drag and Drop in `<canvas>`?**

Yes! Since `<canvas>` is just a drawing surface (not an HTML element container), you have to manually implement drag-and-drop functionality using JavaScript.

```html
<!DOCTYPE html>
<html>
<head>
<title>Page Title</title>
</head>
<body>

<canvas id="canvas" width="500" height="300" style="border:1px solid;"></canvas>

<script>
  let canvas = document.getElementById("canvas");
  let ctx = canvas.getContext("2d");

  // Define a draggable object
  let rect = { x: 50, y: 50, width: 100, height: 100, dragging: false };

  // Draw the rectangle
  function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height); // Clear canvas
    ctx.fillStyle = "blue";
    ctx.fillRect(rect.x, rect.y, rect.width, rect.height);
  }

  // Check if the mouse is inside the rectangle
  function isInsideRect(x, y) {
    return x > rect.x && x < rect.x + rect.width && y > rect.y && y < rect.y + rect.height;
  }

  // Mouse events
  canvas.addEventListener("mousedown", (e) => {
    let mouseX = e.offsetX, mouseY = e.offsetY;
    if (isInsideRect(mouseX, mouseY)) {
      rect.dragging = true;
    }
  });

  canvas.addEventListener("mousemove", (e) => {
    if (rect.dragging) {
      rect.x = e.offsetX - rect.width / 2;
      rect.y = e.offsetY - rect.height / 2;
      draw();
    }
  });

  canvas.addEventListener("mouseup", () => {
    rect.dragging = false;
  });

  draw(); // Initial draw
</script>

</body>
</html>


```

![[Pasted image 20250316214904.png]]

We define a **JavaScript object** to store:

- `x`: The X-coordinate (horizontal position of the rectangle).
- `y`: The Y-coordinate (vertical position of the rectangle).
- `width`: The rectangle’s width.
- `height`: The rectangle’s height.
- `dragging`: A **Boolean flag** that tracks if the user is dragging (`true` = dragging, `false` = not dragging).

![[Pasted image 20250316221333.png]]

![[Pasted image 20250316221506.png]]


```c
(0,0) --------------------------> X-axis
   |  (rect.x, rect.y)      
   |       ┌────────────────────────┐  
   |       |                        |  
   |       |    RECTANGLE AREA      |  
   |       |                        |  
   |       └────────────────────────┘  (rect.x + rect.width, rect.y + rect.height)
   v
 Y-axis

```

If the **mouse position `(x, y)`** is within this rectangle area, the function returns `true`, meaning **the user has clicked inside the rectangle**.

rect = { x: 50, y: 50, width: 100, height: 100 };
let mouseX = 75, mouseY = 75; 

isInsideRect(mouseX, mouseY); // ✅ Returns true (inside)
Why?

75 > 50 ✅ (Right of left boundary)
75 < 150 ✅ (Left of right boundary)
75 > 50 ✅ (Below top boundary)
75 < 150 ✅ (Above bottom boundary)

### ❌ **Mouse is Outside the Rectangle**

js

CopyEdit

`let mouseX = 200, mouseY = 200;   isInsideRect(mouseX, mouseY); // ❌ Returns false (outside)`

**Why?**

- `200 > 50` ✅ (Right of left boundary)
- `200 < 150` ❌ (Fails - it's **past** the right boundary)
- `200 > 50` ✅ (Below top boundary)
- `200 < 150` ❌ (Fails - it's **below** the bottom boundary)

Since **at least one condition failed**, the function **returns false**.

--------------------------
**Chrome devToools**


![[Pasted image 20250316224011.png]]

![[Pasted image 20250316224002.png]]


















