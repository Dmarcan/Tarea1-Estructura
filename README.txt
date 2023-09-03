Integrantes:
-Sean Jamen 100 pts
-Benjamin Velasquez 100 pts
Ambos integrantes trabajamos en conjunto en la realizacion del programa.


Procedimiento:
El usuario debe de ejecutar el programa y seleccionar la opcion que se acomode a lo que desea realizar.Cada una de esta opciones esta explicada en la seccion "Descipcion de funciones".


Descipcion de funciones:

1. Registrar Libro (Título, Autor, Género, ISBN, Ubicación):
   - El usuario ingresa los detalles del libro: título, autor, género, ISBN y ubicación (obtenidos del documento CSV).
   - La aplicación verifica que ningún campo de texto tenga más de 50 caracteres.
   - La aplicación crea un struct para el libro con la información proporcionada.
   - El libro se almacena en la base de datos de libros.

2. Mostrar Datos de Libro (Título, Autor):
   - El usuario introduce el título y autor de un libro.
   - La aplicación busca el libro correspondiente en la base de datos por título y autor.
   - Si el libro es encontrado, se muestran sus detalles, incluyendo las reservas asociadas, si es que hay.
   - Si no se encuentra el libro, se muestra un aviso notificando que no se halló información para el libro pedido.

3. Mostrar Datos todos los libros(titulo, autor):
   - Se muestran por pantalla todos los libros registrados con sus detalles (titulo,autor, genero,ISBN, ubicacion y estado).

4. Reservar Libro (Título, Autor, Nombre del Estudiante):
   - El usuario proporciona el título y autor del libro, así como el nombre del estudiante que desea reservarlo.
   - La aplicación busca el libro en la base de datos según el título y autor ingresados.
   - Si el libro existe y está disponible o ya tiene reservas, se agrega la reserva a la cola de reservas del libro.
   - Si el libro no existe, se muestra un mensaje indicando que el libro pedido no fue hallado.

5. Cancelar Libro(titulo,autor, nombre_estudiante):
   - El usuario proporciona el título y autor del libro, así como el nombre del estudiante que desea eliminar la reserva.
   - La aplicación busca el libro en la base de datos según el título y autor ingresados.
   - Si el libro existe, se elimina al estudiante de la cola de reservas.
   - Si el libro no existe, se muestra un mensaje indicando que el libro pedido no fue hallado.

6. Retirar Libro (Título, Autor, Nombre del Estudiante):
   - El usuario ingresa el título y autor del libro, junto al nombre del estudiante que pretende retirarlo.
   - La aplicación busca el libro correspondiente en la base de datos por título y autor.
   - Si el libro es encontrado y está "Disponible" o el estudiante es el primero en la cola de reservas, se permite el retiro del libro y su estado se cambia a "Prestado".
   - Si el libro ya está "Prestado" o el estudiante no tiene prioridad en la cola de reservas, se muestra un mensaje indicando que el libro no puede ser retirado.
   - Cuando el libro es retirado, se modifica su estado a "Prestado" y se asigna al primer estudiante en la cola de reservas.
7. Devolver Libro (titulo, autor): 
   -  El usuario ingresa el título y autor del libro.
   - Se verifica si el libro tiene alguna cola de reservas, de ser asi su estado pasa a reservado.
   - Sno hay cola de reservas, el estado pasa a Disponible.
8. Mostrar libros prestados():
   - Se muestran por pantalla todos los libros prestados con sus detalles (titulo,autor, genero,ISBN, ubicacion y estado).
9. Importar libros desde un archivo CSV (nombreArchivo):
   - El usuario ingresa el nombre del arhivo a importar.
   - Se cargan todos los datos del archivo(Título,Autor,Género,ISBN,Ubicación,Estado,Reservas).
10. Importar libros desde un archivo CSV (nombreArchivo):
   -Se exportan todos los libros registrados con todos sus detalles(Título,Autor,Género,ISBN,Ubicación,Estado,Reservas) a un archivo CSV indicado por el usuario.
   




