1. ==Given an integer array `nums`, return `true` if any value appears **more than once** in the array, otherwise return `false`.==

**Example 1:**

```java
Input: nums = [1, 2, 3, 3]

Output: true
```

```js
class Solution {

    /**

     * @param {number[]} nums

     * @return {boolean}

     */

  hasDuplicate(nums) {

       nums.sort() // 1,1,2,3,4,5,8,9

       for(let i=1;i<nums.length;i++){

        if(nums[i]==nums[i-1])

        return true

       }
   return false

    }

}

------------------------------------

javascript
class Solution {
    /**
     * @param {number[]} nums
     * @return {boolean}
 * using hash set 
     */
    hasDuplicate(nums) {
        return new Set(nums).size < nums.length;
    }
}


```

==2.Given two strings `s` and `t`, return `true` if the two strings are anagrams of each other, otherwise return `false`.==

An **anagram** is a string that contains the exact same characters as another string, but the order of the characters can be different.

**Example 1:**

```java
Input: s = "racecar", t = "carrace"

Output: true
```


**Example 2:**

```java
Input: s = "jar", t = "jam"

Output: false
```

```js
class Solution {

    /**

     * @param {string} s

     * @param {string} t

     * @return {boolean}

     */

    isAnagram(s, t) {

        const reverseS = s.split("").reverse().join("")

        const reverseT = t.split("").reverse().join("")

  

        if( s== reverseS || t== reverseT){

            return true

        }

  

    return false

    }

}
```
  

 ###### *turn str to array and then sort alpbatically*
```js
 let s = "sabber"
 s.split("").sort()
  //  ['a', 'b', 'b', 'e', 'r', 's']
```

==Given an array of integers `nums` and an integer `target`, return the indices `i` and `j` such that `nums[i] + nums[j] == target` and `i != j`.==

You may assume that _every_ input has exactly one pair of indices `i` and `j` that satisfy the condition.

Return the answer with the smaller index first.

**Example 1:**

```java
Input: 
nums = [3,4,5,6], target = 7

Output: [0,1]
```


Explanation: `nums[0] + nums[1] == 7`, so we return `[0, 1]`.

**Example 2:**

```java
Input: nums = [4,5,6], target = 10

Output: [0,2]
```

```js
class Solution {

    /**

     * @param {number[]} nums

     * @param {number} target

     * @return {number[]}

     */

    twoSum(nums, target) {

        for (let i=0;i< nums.length; i++){

          for (let j=i+1;== j< nums.length;j++){
          // j=1 X , j=i+1 hobe 

             if (nums[j]+nums[i]==target){

                return [j,i]

            }

          }

        }  

    }

}

// using hashmap 
class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        const prevMap = new Map();

        for (let i = 0; i < nums.length; i++) {
            const diff = target - nums[i];
            if (prevMap.has(diff)) {
                return [prevMap.get(diff), i];
            }

            prevMap.set(nums[i], i);
        }

        return [];
    }
}


```

![[Pasted image 20241210135104.png]]

![[Pasted image 20241210135125.png]]
