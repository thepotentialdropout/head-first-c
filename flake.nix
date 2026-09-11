{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: let 
    pkgs = nixpkgs.legacyPackages.x86_64-linux;

    opencv4Gtk = (pkgs.opencv4.override  { enableGtk3 = true; })
      .overrideAttrs (old: {
        cmakeFlags = old.cmakeFlags ++ [
          "-DWITH_GTK=ON"
          "-DWITH_GTK_2_X=OFF"
        ];
    });
  in {
    devShells.x86_64-linux.default = pkgs.mkShell {
      stdenv = pkgs.clangStdenv;
      packages = with pkgs; [
        cmake
        clang
        gdb
      ];
      buildInputs = with pkgs; [
        pkg-config
        opencv4Gtk
      ];

    };
  };
}
