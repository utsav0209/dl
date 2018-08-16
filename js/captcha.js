
// Captcha Script
var code;
function checkform(theform){
	var msg = "";

	if(theform.CaptchaInput.value == ""){
		msg += "- Please Enter CAPTCHA Code.\n";
	}
	if(theform.CaptchaInput.value != ""){
		if(ValidCaptcha(theform.CaptchaInput.value) == false){
				msg += "- The CAPTCHA Code Does Not Match.\n";
			}
		}
		if(msg != ""){
			alert(msg);
			return false;
		}
	}

	var a = Math.ceil(Math.random() * 9)+ '';
	var b = Math.ceil(Math.random() * 9)+ '';
	var c = Math.ceil(Math.random() * 9)+ '';
	var d = Math.ceil(Math.random() * 9)+ '';
	var e = Math.ceil(Math.random() * 9)+ '';
	code = a + b + c + d + e;
	
	var canv = document.createElement("canvas");
	canv.id = "captcha";
	canv.width = 100;
	canv.height = 50;
	var ctx = canv.getContext("2d");
	ctx.font = "25px Georgia";
	ctx.strokeText(code, 0, 30);
	document.getElementById("captcha").appendChild(canv); 

	function ValidCaptcha(){
		var str1 = removeSpaces(document.getElementById('CaptchaInput').value);
		if (str1 == code){
			return true;
		}else{
			return false;
		}
}

function removeSpaces(string){
	return string.split(' ').join('');
}
