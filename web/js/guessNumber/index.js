const randomNum = Math.floor(Math.random() * 100);
console.log(randomNum);
const againButton = document.querySelector('#again');
const winLoseText = document.querySelector('#win-lose-text');
const highscoreText = document.querySelector('#highscore');
const countText = document.querySelector('#count');
const guessInput = document.querySelector('#guess');
const outputText = document.querySelector('#output');

highscoreText.innerText = sessionStorage.getItem('highscore') || '0';

guessInput.addEventListener('keydown', function (event) {
    if (event.key === "Enter") {
        if (randomNum === Number(guessInput.value)) {
            winLoseText.innerText = "You win";
            outputText.innerText = "";
            guessInput.disabled = true;
            if (Number(highscoreText.innerText) < Number(countText.innerText)) {
                highscoreText.innerText = countText.innerText;
                sessionStorage.setItem('highscore', highscoreText.innerText);
            }
        } else {
            if (randomNum > Number(guessInput.value) && randomNum - Number(guessInput.value) >= 20) {
                outputText.innerText = "Superlow";
            } else if (randomNum < Number(guessInput.value) && Math.abs(randomNum - Number(guessInput.value)) >= 20) {
                outputText.innerText = "Superhigh";
            } else if (randomNum > Number(guessInput.value)) {
                outputText.innerText = "Low";
            } else if (randomNum < Number(guessInput.value)) {
                outputText.innerText = "High";
            }
            countText.innerText = Number(countText.innerText) - 1;
            guessInput.value = "";
            if (countText.innerText <= 0) {
                winLoseText.innerText = "You lose";
                guessInput.disabled = true;
            }
        }
    }
});

againButton.addEventListener('click', function () {
    window.location.reload()
});
