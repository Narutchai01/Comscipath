const car1 = document.querySelector("#car1")
const car2 = document.querySelector("#car2")
const car3 = document.querySelector("#car3")
const car4 = document.querySelector("#car4")
const car5 = document.querySelector("#car5")


const changeClass = (car) => {
    car.id = "car1-active"
}

car1.addEventListener("click", () => changeClass(car1))
car2.addEventListener("click", () => changeClass(car2))
car3.addEventListener("click", () => changeClass(car3))
car4.addEventListener("click", () => changeClass(car4))
car5.addEventListener("click", () => changeClass(car5))