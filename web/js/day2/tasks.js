"use strict"

//task1
const input = prompt("Input a text");

function toUppercase(input) {
    const words = input.split(" ");
    const firstWord = words[0].toUpperCase();
    words.shift();
    const sentence = words.join(' ');
    const result = firstWord.concat(' ', sentence);
    return result;
}
console.log(toUppercase(input));

//task2
function DivideArray(arr, size) {
    const subArrays = [];
    for (let i = 0; i < arr.length; i += size) {
        subArrays.push(arr.slice(i, i + size))
    }
    return subArrays;
}
console.log(DivideArray([1, 2, 3, 4, 5, 6, 7, 8], 3));

//task3
function SumOfNumbers(object) {
    let sum = 0;
    for (const [key, value] of Object.entries(object)) {
        if(!isNaN(value)){
            sum += value;
        }
    }
    return sum;
}
const object = { a: 10, b: 20, c: 'string', d: 12 }
console.log(SumOfNumbers(object));

//task4
function GetVowelsCount(string) {
    const vowels = 'aeiouAEIOU';
    let vowelsCount = 0;

    for (let i = 0; i < string.length; i++) {
        if (vowels.indexOf(string[i]) !== -1) {
            vowelsCount += 1;
        }
    }
    return vowelsCount;
}
console.log(GetVowelsCount('Today is the best day of my life'));

//task5
function SumOfNumbers(array) {
    let SumOfPositiveNum = 0;
    let SumOfNegativeNum = 0;

    for (const num of array) {
        if (num > 0) {
            SumOfPositiveNum += num;
        }
        else {
            SumOfNegativeNum += num;
        }
    }
    const result = { positive: SumOfPositiveNum, negative: SumOfNegativeNum };
    return result;
}
console.log(SumOfNumbers([10, -12, 30, -1, -8, 0, 14, -33, 20]));

//task6
const data = [
    { id: 1, name: 'Name one', city: 'Stepanakert'},
    { id: 2, name: 'Name one', city: 'Yerevan' },
    { id: 3, name: 'Name one', city: 'Moscow' },
    { id: 4, name: 'Name one', city: 'Stepanakert' },
    { id: 5, name: 'Name one', city: 'Yerevan' },
];

const arr = [];

function GetUniqueCities(cities) {
    for (let i = 0; i < cities.length; i++) {
        arr.push(cities[i].city);
    }
    const Array = [...new Set(arr)];
    return Array;
}
console.log(GetUniqueCities(data));

//task7
function AreStringsAnagram(input1, input2) {
    let string1 = input1.toLowerCase().replace(/[^a-z0-9]/gi, '').split('').sort().join('');
    let string2 = input2.toLowerCase().replace(/[^a-z0-9]/gi, '').split('').sort().join('');
    return string1 === string2;
}
console.log(AreStringsAnagram('RAIL! SAFETY!', 'fairy tales'));
console.log(AreStringsAnagram('Hi there', 'Bye there'));