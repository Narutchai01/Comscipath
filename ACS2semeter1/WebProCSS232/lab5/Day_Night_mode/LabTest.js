const btn = document.querySelector('.DayLight');

const ChangeTheme = () => {
    document.querySelector('.contecnt').classList.toggle('contecnt-active');
    document.querySelector('span').style.color = 'blue';
    if (document.querySelector('.contecnt-active')) {
        btn.innerHTML = 'Activate the day mode';
    } else {
        btn.innerHTML = 'Activate the night mode';
    }
}

btn.addEventListener('click', ChangeTheme);