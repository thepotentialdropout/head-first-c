{
  pkgs,
  lib,
  config,
  ...
}:

{
  languages = {
    c.enable = true;
    c.debugger = pkgs.gdb;
  };

  packages = with pkgs; [
    gnumake
    valgrind
  ];

}

