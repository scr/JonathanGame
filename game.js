var game =
    (function(){
	 var theMap = [
	     "        ",
	     "      E ",
	     "        ",
	     "        ",
	     "        ",
	     "        ",
	     "        ",
	     "        ",
	 ];

	 function moveDirection() {
	     var dir = $(this).prop('id');
	 }
	 function updateBoard() {
	     $('#gameboard').empty();
	     $('#gameboard-template').tmpl({rows: theMap}).appendTo('#gameboard');
	 }
	 function Init() {
	     $('button').live({
		 click: moveDirection,
	     });
	     updateBoard();
	 }
	 return {
	     Init: Init
	 };
     })();
