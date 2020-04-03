let burgerMenuOpen = document.querySelector(".burger-menu.open");
let burgerMenuClose = document.querySelector(".burger-menu.close");
let mobileMenu = document.querySelector(".mobile-menu");
mobileMenu.style.height = "0px";
burgerMenuOpen.onclick = () => {
  mobileMenu.style.height = "200px";
  burgerMenuOpen.style.display = "none";
  burgerMenuClose.style.display = "block";
};
burgerMenuClose.onclick = () => {
  mobileMenu.style.height = "0px";
  burgerMenuClose.style.display = "none";
  burgerMenuOpen.style.display = "block";
};
let mainContent = document.querySelector("main");
mainContent.onclick = () => {
  if(burgerMenuClose.style.display == "block"){
    mobileMenu.style.height = "0px";
    burgerMenuClose.style.display = "none";
    burgerMenuOpen.style.display = "block";
  }
};