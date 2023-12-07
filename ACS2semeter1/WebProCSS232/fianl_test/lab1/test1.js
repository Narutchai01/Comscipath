const outer = document.querySelector('#outer');
const inner = document.querySelector('#inner');
const middle = document.querySelector('#middle');
const check = document.querySelector('#check')
const button = document.querySelector(".button")






const outerClick = () => {
    outer.id = "outer-active";
}
const middleClick = (event) => {
    middle.id = "middle-active";
    if (check.checked) {
        event.stopPropagation();
    }
}
const innerClick = (event) => {
    inner.id = "inner-active";
    if (check.checked) {
        event.stopPropagation();
    }

}

const resetId = () => {
    outer.id = "outer"
    middle.id = "middle"
    inner.id = "inner"
}

outer.addEventListener('click', outerClick);
inner.addEventListener('clcik', innerClick);
middle.addEventListener('clcik', middleClick);
button.addEventListener('click', resetId)
