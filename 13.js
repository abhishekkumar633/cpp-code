let new_btn=document.createElement("button");
new_btn.innerText="click me";
console.log(new_btn);

let div=document.querySelector("div");
div.before(new_btn);

new_btn.style.backgroundColor="red";
new_btn.style.color='yellow'


let para=document.querySelector("p");
para.classList.add=("another-class");