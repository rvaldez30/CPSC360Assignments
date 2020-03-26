//Reynaldo Valdez
//Program Assignment 8

//longest word finder function

function longestEword(Elong) {
	let Eword = "";
	for (let i = 0; i < Elong.length; i++){
		if (Eword.length < Elong[i].length){
			Eword = Elong[i];
		}
	}
	return Eword;
}

//Array right here

let wordsE = [];
//user enters String
let userWords = prompt("Enter a string: ");
//alert methos in action
alert("User input the string: " + userWords);

userWords = userWords.split(" ");

for (let i = 0; i < userWords.length; i++) {
	let userEWord = userWords[i];
	for (let j = 0; j < userEWord.length; j++){
		if (userEWord[j] === "e"){
			wordsE.push(userEWord);
			break;
		}
	}
}
//intializing variable 

let longestW = longestEword(wordsE);

//Outputs should be 
// words that contain "e"
//Longest word with "e"
// num of chracters in longest "e" word 

alert (" The number of words you entered that contained the letter 'e' is: " + wordsE.length);
alert (" The longest word you entered that contains the letter 'e' is: " + longestW);
alert (" The number of characters in the longest 'e' word you entered is: " + longestW.length);
