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

  packages = [
    pkgs.gnumake
    pkgs.valgrind
  ];

}

