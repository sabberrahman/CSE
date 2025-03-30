#### String:

- Index positions:  
    `s[0]` = `'h'`, `s[1]` = `'e'`, `s[2]` = `'l'`, `s[3]` = `'l'`, `s[4]` = `'o'`.

#### Hash Table:

We count the occurrences of characters using `hash[s[i]]++`.

- Start with an empty hash table.
- For `i = 0`:  
    `s[0] = 'h'` → `hash['h']++` → `hash = {'h': 1}`
- For `i = 1`:  
    `s[1] = 'e'` → `hash['e']++` → `hash = {'h': 1, 'e': 1}`
- For `i = 2`:  
    `s[2] = 'l'` → `hash['l']++` → `hash = {'h': 1, 'e': 1, 'l': 1}`
- For `i = 3`:  
    `s[3] = 'l'` → `hash['l']++` → `hash = {'h': 1, 'e': 1, 'l': 2}`
- For `i = 4`:  
    `s[4] = 'o'` → `hash['o']++` → `hash = {'h': 1, 'e': 1, 'l': 2, 'o': 1}`

here is no concept of a positional **index** in a hash table like in arrays or strings.

``` c++
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string s = "hello";
    unordered_map<char, int> hash;
    
    for (int i = 0; i < s.length(); i++) {
        hash[s[i]]++; // Increment the count for character s[i]
    }

    for (auto pair : hash) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}

h: 1 e: 1 l: 2 o: 1

```

```python

arr = [10, 20, 30]
print(arr[0]) 
# Output: 10 (accessing by index 0)


hash_table = {"dhaka": 1, "new york": 2} print(hash_table["dhaka"]) 
# Output: 1 (accessing by key "dhaka")
hash("dhaka") # This produces an integer, say 12345 (in Python, the exact value depends on runtime).

```

#### What Happens Internally:

1. When you insert `"dhaka": 1`, the key `"dhaka"` is hashed:
    
    - `hash("dhaka")` → Produces an integer (e.g., `12345`).
    - The value `1` is stored at the memory location determined by `12345`.
2. When you access `hash_table["dhaka"]`:
    
    - `"dhaka"` is hashed again → `hash("dhaka") = 12345`.
    - The hash table uses this to find the stored value at `12345`, which is `1`.
**********

**Hash Tables Don’t Use Integer Indices:**

- **Unlike arrays/lists, hash tables don’t use numeric indices.**
- *They rely on keys, **which are hashed into integers behind the scenes.**

### How a Set Works Internally:

Sets use a **hash table** under the hood to ensure:

1. **Fast membership testing** (O(1)O(1)O(1) on average).
2. **Uniqueness**: Each element is hashed, and the hash is used to check if it already exists before adding it to the se

When you add a new element:

- It is hashed.
- The set checks if the hash value already exists. If it does, the element is ignored (because it’s a duplicate). Otherwise, it’s added.

### Comparison with Arrays and Hash Tables:

| ==**Feature**==     | ==**Set**==                     | ==**Array (List)**==      | ==**Hash Table (Dictionary)**==    |
| ------------------- | ------------------------------- | ------------------------- | ---------------------------------- |
| **Duplicates**      | Not allowed                     | Allowed                   | Keys: Not allowed, Values: Allowed |
| **Order**           | **Unordered**                   | Ordered                   | Keys: Unordered                    |
| **Access**          | No positional access            | Positional access (index) | Key-based access                   |
| **Membership Test** | Fast (O(1)O(1)O(1))             | Slow (O(n)O(n)O(n))       | Fast (O(1)O(1)O(1))                |
| **Use Case**        | Unique elements, set operations | Ordered data              | Key-value mappings                 |

