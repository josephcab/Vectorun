#! /usr/bin/env python

def options(opt):
    pass

def configure(cfg):
    pass

def build(bld):
    bld.shlib(
        source = '''
            src/action_drop.cc
            src/api.cc
            src/entry.cc
            src/game_state.cc
            src/interface.cc
            src/rules.cc
        ''',
        defines = ['MODULE_COLOR=ANSI_COL_BROWN', 'MODULE_NAME="rules"'],
        target = 'connect4',
        use = ['stechec2'],
    )

    bld.install_files('${PREFIX}/share/stechec2/connect4', [
        'connect4.yml',
    ])