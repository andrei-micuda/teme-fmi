const showSlide = (i) => {
  slides.forEach((slide) => {
    slide.style.display = "none";
  }
  );
  slides[i].style.display = "block";
  let tmp = document.querySelectorAll(".dots div");
  tmp.forEach((x) => {
    x.className = "";
  }
  );
  tmp[i].className = "active";
  currentSlide = i;
};

const prevSlide = () => {
  if(currentSlide == 0) currentSlide = slides.length - 1;
  else currentSlide--;
  showSlide(currentSlide);
};

const nextSlide = () => {
  if(currentSlide == slides.length - 1) currentSlide = 0;
  else currentSlide++;
  showSlide(currentSlide);
};

let slides = document.querySelectorAll(".gallery img");
let dotsHTML = "";
for(let i=0; i<slides.length; i++){
  dotsHTML += `<div onclick="showSlide(${i})"></div>`;
}
let dots = document.querySelector(".dots");
dots.innerHTML = dotsHTML;

let currentSlide = 0;
showSlide(currentSlide);