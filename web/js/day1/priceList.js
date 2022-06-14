"use strict";

alert ("We have the following products\n 1.Snickers-200AMD\n 2.Coca-Cola-400AMD\n 3.Jermuk-99.9AMD\n 4.Chocolate-1200AMD\n 5.Candy-350AMD\n");

const snickersPrice = 200,
      colaPrice = 400,
      jermukPrice = 99.9,
      chocolatePrice = 1200,
      candyPrice = 350;

let snickersCount,
    colaCount,
    jermukCount,
    chocolateCount,
    candyCount;

snickersCount = prompt("Enter the count of snickers");
colaCount = prompt("Enter the count of cola");
jermukCount = prompt("Enter the count of jermuk");
chocolateCount = prompt("Enter the count of chocolate");
candyCount = prompt("Enter the count of candy");

let sum = (snickersPrice * snickersCount + colaPrice * colaCount + jermukPrice * jermukCount + chocolatePrice * chocolateCount + candyPrice * candyCount);
let payment;

if (sum === 0) {
    alert("You didn't buy anything")
} else {
    alert("You have to pay " + sum + " AMD");
    payment = prompt("Enter your amount of money: ");
    if (payment > sum) {
        alert("Your surrender is " + (payment - sum) + " AMD");
    } else if (payment < sum) {
        alert("You haven't enough money");
    } else if (isNaN(payment)) {
        alert("You can't do shopping");
    }
}

if (payment > sum) {
    console.log(`Total price: ` + sum + ` AMD`);
    console.log(`Payment: ` + payment + ` AMD`);
    console.log(`Surrender: ` + (sum - payment) + ` AMD`);
    console.log(`\nProducts: `);

    if (snickersCount > 0) {
        console.log(`Snickers - ` + snickersCount + ` pack ` + (snickersPrice * snickersCount) + ` AMD`);
    }
    if (colaCount > 0) {
        console.log(`Coca-Cola - ` + colaCount + ` bottle ` + (colaPrice * colaCount) + ` AMD`);
    }
    if (jermukCount > 0) {
        console.log(`Jermuk - ` + jermukCount + ` bottle ` + (jermukPrice * jermukCount) + ` AMD`);
    }
    if (chocolateCount > 0) {
        console.log(`Chocolate - ` + chocolateCount + ` bar ` + (chocolatePrice * chocolateCount) + ` AMD`);
    }
    if (candyCount > 0) {
        console.log(`Candy - ` + candyCount + ` pack ` + (candyPrice * candyCount) + ` AMD`);
    }
}