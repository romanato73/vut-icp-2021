BlockEdit:
BlockEdit is an editor and interpret of hierarchically structured function blocks.
The storage is implemented using a JSON file, which is located in the path: src/Storage/categories.json.
Editor can create customisable atomic blocks, which have their inputs, outputs and code.
After connecting block with input/output or another function blocks, it is possible to
generate the code, which represents the behaviour of blocks.

Testing categories:
- For testing categories there are 5 different storages inside examples/storage:
    - experimental - experimental function blocks
    - inputs_outputs - testing a lot of inputs/outputs
    - logical_extended - extended logical blocks
    - mathematical - base mathematical functions
    - all - all above in one storage
- Just copy one of the storage into: src/Storage/

Testing codes:
- Inside examples/programs are generated codes with the image of their implementation on the scene

Implemented functionallity:
- Categories
    - Categories library (in the left sidebar)
    - Creating categories
    - Editing categories
    - Deleting categories
- Atomic blocks
    - Atomic blocks library (in the left sidebar)
    - Creating atomic blocks (into category or just into scene)
    - Editing atomic blocks (inside category or just inside scene)
    - Deleting atomic blocks (in category or in scene)
- Code generating
    - Generates the code from the connected blocks
    - Connecting different types of inputs
    - Connecting outputs (makes the std::cout)

Functionallity restrictions: -

GUI
- GUI contains two main parts:
    - Sidebar
    - The main scene
- Sidebar contains:
    - Mode switch buttons
    - In "Create" mode it shows the subwidget under mode buttons which is used for switching
      creation of blocks, connections, inputs and outputs
    - Generating program from the scene
    - The scene cleaner, which cleans the scene

Application modes
- Select (mouse pointer)
    - In this mode objects on the scene are movable or block from the category can be added into scene
- Create (plus symbol)
    - In this mode the new objects are created (blocks, connections, inputs, outputs)
    - In this mode application will show the subwidget where you can switch these objects
    - After mouse press on the scene the object is created on the place where the mouse points
- Edit (edit symbol)
    - In this mode blocks can be edited in the category or in the scene
    - In case the clicked block is in the sidebar the new dialog shows up with the editable options
      (The block is also edited inside the storage)
    - In case the clicked block is on the scene the new dialog shows up with the editable options
      (The block is not edited in the storage only on the scene)
- Delete (trash symbol)
    - In this mode blocks are deleted on the scene or in the category (in the sidebar)
    - In case the clicked block is in the sidebar (except the default) it is deleted completely
      from the storage
    - In case the clicked block is on the scene only the actual block on the scene is deleted

Category creation
- Category is created by clicking on the plus symbol next to "Categories"
- After clicking the plus button new dialog shows up where the category name is set.

Block creation
- Blocks can be added into category or only into scene
- In "Create" mode after clicking on the scene dialog shows up, where the block is initialized
- If no category is set the block is placed only into the scene
- Inputs:
    - Inputs are written with the following format: "TYPE:NAME"
    - Each input is separated with new line
    - Allowed types are: int,float,string,bool
- Outputs:
    - Same as inputs
- Code:
    - Code is written as the function body
    - Each function is of the type void, so each output must be assigned into the output variable
    - The example code of two string concatenation (inputs: string:A,string:B | outputs: string:C):
    C = A + B;

Code generation
- Code is generated after clicking on the button next to "Build program"
- The new dialog shows up, where the file name and path are selected, in this path the file is stored (as .txt file)
- After clicking on "Build a program" the program is generated into selected file