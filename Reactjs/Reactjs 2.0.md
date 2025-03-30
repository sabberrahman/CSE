A Controlled Component is one that takes its current value through props and notifies changes through callbacks like `onChange`. A parent component "controls" it by handling the callback and managing its own state and passing the new values as props to the controlled component. You could also call this a "dumb component".

A Uncontrolled Component is one that stores its own state internally, and you query the DOM using a `ref` to find its current value when you need it. This is a bit more like traditional HTML.

Most native React form components support both controlled and uncontrolled usage:

```jsx
// Controlled:
<input type="text" value={value} onChange={handleChange} />

// Uncontrolled:
<input type="text" defaultValue="foo" ref={inputRef} />
// Use `inputRef.current.value` to read the current value of <input>
```


Pure components re-render only when the props passed to the component changes. For example, if you have a pure child component inside a parent component state changes in the parent component will not re-render the child component unless the props passed to the child component change.

To create a pure component, you can use the `memo` function from React. I==t is a higher order component which takes a component as an argument and returns a new component. The new component renders only if the props change.==

```javascript
import React, { memo } from 'react';

const ChildComponent = ({ name }) => {
  console.log('Rendering child component');
  return <div>{name}</div>;
};

const PureChildComponent = memo(ChildComponent);

const ParentComponent = () => {
  const [count, setCount] = useState(0);
  const [name, setName] = useState('John');

  return (
    <div>
      <button onClick={() => setCount(count + 1)}>Count - {count}</button>
      <button onClick={() => setName('Jane')}>Change name</button>
      <PureChildComponent name={name} />
    </div>
  );
};
```


Refs are used to get reference to a DOM node or an instance of a component. They help to access the DOM nodes or React elements created in the render method. You can also use refs when you want a component to “remember” some information, but you don’t want that information to trigger new renders, you can use a ref.



------------------------
useEffect and its dependecey

```ts
useEffect(()=>{
console.log("this will run everytime when a state is changed. ANY STATE")
})

useEffect(()=>{
console.log("this will run once when page is loaded")
},[])

const [username,setUsername]= useState("sabber")
useEffect(()=>{
console.log("this will run when ${username} is changed")
},[username])

```

we might see our logs twice in broswer, thats bcz we are using -
```js
<React.StrictMode>
  <App/>
</React.StrictMode>
```

```js
%% we can have multiple useEfect %%

const [username,setUsername]= useState("sabber")
const [pass,setPass]= useState("")

useEffect(()=>{
console.log("this will run when ${username} is changed")
},[username])

useEffect(()=>{
console.log("this will run when ${pass} is changed")
},[pass])

```


use case will be, we can use empty array to have smting load when page is first loaded, and then we can have other useEddefct with some dependecy or no dependecy at all.


-----------------------


































