const outer = document.querySelector('#outer');
const inner = document.querySelector('#inner');
const middle = document.querySelector('#middle');





const outerClick = () => {
    outer.id = 'outer-active';
}

outer.addEventListener('click', outerClick);