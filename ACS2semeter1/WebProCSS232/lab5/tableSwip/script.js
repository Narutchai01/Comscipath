
const Bigbg = document.querySelector('.bg-1');

const Swip = () => {
    document.querySelector('.s-1').classList.toggle('s-1-active');
    document.querySelector('.s-2').classList.toggle('s-2-active');
    document.querySelector('.s-3').classList.toggle('s-3-active');
    document.querySelector('.s-4').classList.toggle('s-4-active');
}

Bigbg.addEventListener('click', Swip);