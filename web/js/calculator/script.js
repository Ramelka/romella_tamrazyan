function Calculate(option) {
    let num1 = Number(document.getElementById("num1").value);
    let num2 = Number(document.getElementById("num2").value);
    switch(option) {
        case "+":
            let add = num1 + num2
            document.getElementById("answer").innerHTML = add;
            break;
        case "-":
            let subtract = num1 - num2;
            document.getElementById("answer").innerHTML = subtract;
            document.getElementById("sign").innerHTML = document.getElementById("minus").innerHTML;
            break;
        case "*":
            let multiply = num1 * num2;
            document.getElementById("answer").innerHTML = multiply;
            document.getElementById("sign").innerHTML = document.getElementById("mult").innerHTML;
            break;
        case "/":
            let divide = num1 / num2;
            document.getElementById("answer").innerHTML = divide;
            document.getElementById("sign").innerHTML = document.getElementById("div").innerHTML;
            break;
    }
}

function Reset() {
    document.getElementById("answer").innerHTML = " ";
    document.getElementById("num1").value = " ";
    document.getElementById("num2").value = " ";
    document.getElementById("sign").innerHTML = document.getElementById("plus").innerHTML;;
}

document.addEventListener('keydown', function(event){
	if(event.key === "Escape"){
		Reset();
	}
});