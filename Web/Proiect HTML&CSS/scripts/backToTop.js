function scrollToTop(){
  window.scrollTo(0, 0);
}

window.onscroll = () => {
  let verticalScroll = window.pageYOffset || document.documentElement.scrollTop || document.body.scrollTop || 0;
  let backToTop = document.querySelector(".backToTop");
  if(verticalScroll > 75 && !backToTop.classList.contains("shiftUp")){
    backToTop.classList.remove("shiftDown");
    backToTop.classList.add("shiftUp");
  }
  else if(verticalScroll < 75 && backToTop.classList.contains("shiftUp")){
    backToTop.classList.remove("shiftUp");
    backToTop.classList.add("shiftDown");
  }
}