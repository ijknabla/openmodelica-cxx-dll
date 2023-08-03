model CallDLL

    function hello_world
        external "C" hello_world()
        annotation(Library="mock");
    end hello_world;

initial algorithm

    hello_world();

end CallDLL;
