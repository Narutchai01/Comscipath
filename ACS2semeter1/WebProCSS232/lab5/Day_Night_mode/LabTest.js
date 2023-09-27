console.log('LabTest.js');

document.querySelector('.DayLight').addEventListener('click', function () {
    document.querySelector('.contecnt').classList.toggle('contecnt-active');
    if (this.innerHTML === 'Activate the night mode') {
        this.innerHTML = 'Activate the day mode';
    } else {
        this.innerHTML = 'Activate the night mode';
    }
});