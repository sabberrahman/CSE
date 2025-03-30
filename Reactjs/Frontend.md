In CSS, the difference between **inline**, **inline-block**, and **block** elements is on the way they’re rendered in the web page:

- **Inline**: Inline elements don’t have a width or height. Instead, they don’t start on a new line and take up only the width that’s required (based on their content). Examples: <span>, <a>.
- **Inline-block**: Just like inline elements, here the DOM elements do not start on a new line, however, they do allow you to set a height and width on them. Example: <img>.
- **Block**: Elements start on a new line, taking up the full width available by default. Their width and height can be set by you. Examples: <div>, <p>.




-----------------------------

Purely from the HTML side:

- **Use Semantic HTML**: Use tags like <header>, <nav>, <main>, <article>, <section>, and <footer> to provide meaningful structure.
- **Proper Heading Hierarchy**: Use headings (<h1> to <h6>) correctly, making sure <h1> is used once per page for the main title, followed by <h2>, <h3>, etc.
- **Meta Tags**: Include relevant <meta> tags, such as description, keywords, and viewport, to provide metadata about the website.
- **Alt Attributes on images**: Use alt attributes for images to describe the content, improving accessibility and search engine understanding.

On top of that:

 **Internal Linking**: Make sure to use internal links to connect content within your web site, helping search engines crawl and understand the site structure.




![[Pasted image 20250314235217.png]]



![[Pasted image 20250315000111.png]]


The main set of metrics to monitor for web apps are:

1. First Contentful Paint (FCP): Time until the first piece of content is rendered.
2. Largest Contentful Paint (LCP): Time until the largest content element is rendered.
3. Time to Interactive (TTI): Time until the page is fully interactive.
4. Total Blocking Time (TBT): Total time during which the main thread is blocked.
5. Cumulative Layout Shift (CLS): Measures visual stability.












