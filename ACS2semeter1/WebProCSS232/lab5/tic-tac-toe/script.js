const cells = document.querySelectorAll('.cell');
const message = document.getElementById('message');
const resetButton = document.querySelector('button');

let currentPlayer = 'X';
let board = ['', '', '', '', '', '', '', '', ''];
let gameOver = false;

// Function to make a move
function makeMove(index) {
    if (!gameOver && board[index] === '') {
        board[index] = currentPlayer;
        cells[index].textContent = currentPlayer;
        cells[index].classList.add(currentPlayer);

        if (checkWin(currentPlayer)) {
            message.textContent = `${currentPlayer} wins!`;
            gameOver = true;
        } else if (board.indexOf('') === -1) {
            message.textContent = "It's a draw!";
            gameOver = true;
        } else {
            currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
            message.textContent = `It's ${currentPlayer}'s turn!`;

            if (currentPlayer === 'O') {
                setTimeout(computerMove, 500);
            }
        }
    }
}

// Function to determine if a player has won
function checkWin(player) {
    const winningCombos = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],
        [0, 3, 6], [1, 4, 7], [2, 5, 8],
        [0, 4, 8], [2, 4, 6]
    ];

    for (const combo of winningCombos) {
        if (combo.every(index => board[index] === player)) {
            combo.forEach(index => cells[index].classList.add('win'));
            return true;
        }
    }

    return false;
}

// Function to reset the board
function resetBoard() {
    board = ['', '', '', '', '', '', '', '', ''];
    currentPlayer = 'X';
    gameOver = false;
    cells.forEach(cell => {
        cell.textContent = '';
        cell.classList.remove('X', 'O', 'win');
    });
    message.textContent = 'Your turn!';
}

// Function for computer's move (randomly)
function computerMove() {
    const emptyCells = board.reduce((acc, val, index) => {
        if (val === '') acc.push(index);
        return acc;
    }, []);

    const randomIndex = Math.floor(Math.random() * emptyCells.length);
    makeMove(emptyCells[randomIndex]);
}

// Add click event listeners to cells
cells.forEach((cell, index) => {
    cell.addEventListener('click', () => makeMove(index));
});

// Add click event listener to reset button
resetButton.addEventListener('click', resetBoard);
