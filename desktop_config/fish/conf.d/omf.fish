# Path to Oh My Fish install.
set -q XDG_DATA_HOME
  and set -gx OMF_PATH "$XDG_DATA_HOME/omf"
  or set -gx OMF_PATH "$HOME/.local/share/omf"

# Load Oh My Fish configuration.
source $OMF_PATH/init.fish

set -g theme_powerline_fonts no
set -g theme_nerd_fonts yes
set -g theme_display_git yes
set -g theme_display_git_dirty yes
set -g theme_display_git_untracked yes
set -g theme_display_git_ahead_verbose yes
set -g theme_display_git_dirty_verbose yes
set -g theme_display_git_stashed_verbose yes
set -g theme_use_abbreviated_branch_name yes
set -g theme_display_vagrant yes
set -g theme_display_docker_machine yes
set -g theme_display_k8s_context yes
set -g theme_display_hg yes
set -g theme_display_virtualenv no
set -g theme_display_ruby no
set -g theme_display_nvm yes
set -g theme_display_user ssh
set -g theme_display_hostname ssh
set -g theme_display_vi no
set -g theme_display_date yes
set -g theme_display_cmd_duration yes
set -g theme_title_display_process yes
set -g theme_title_display_path no
set -g theme_title_display_user yes
set -g theme_title_use_abbreviated_path no
set -g theme_date_format "+%a %H:%M"
set -g theme_avoid_ambiguous_glyphs yes
set -g theme_show_exit_status yes
set -g theme_display_jobs_verbose yes
set -g default_user your_normal_user
set -g fish_prompt_pwd_dir_length 0
set -g theme_project_dir_length 1
set -g theme_newline_cursor yes
set -g theme_newline_prompt ' >'

# setting bobthefish theme
set -g theme_color_scheme base16-dark   

# Base16-Monokai
#
# color values from https://github.com/chriskempson/base16-vim/blob/037f328/colors/base16-monokai.vim
# Adapted from https://gist.github.com/GEOFBOT/71a0a4f2afdc662004e580ec3334bdb4

function bobthefish_colors -S -d 'Define a custom bobthefish color scheme'
  __bobthefish_colors base16-dark

  set -l base00 272822
  set -l base01 383830
  set -l base02 49483e
  set -l base03 75715e
  set -l base04 a59f85
  set -l base05 f8f8f2
  set -l base06 f5f4f1
  set -l base07 f9f8f5
  set -l base08 f92672 # red
  set -l base09 fd971f # orange
  set -l base0A f4bf75 # yellow
  set -l base0B a6e22e # green
  set -l base0C a1efe4 # cyan
  set -l base0D 66d9ef # blue
  set -l base0E ae81ff # violet
  set -l base0F cc6633 # brown

  set -l colorfg $base02

  set -x color_initial_segment_exit     $base05 $base08 --bold
  set -x color_initial_segment_su       $base05 $base0B --bold
  set -x color_initial_segment_jobs     $base05 $base0D --bold

  set -x color_path                     $base02 $base05
  set -x color_path_basename            $base02 $base06 --bold
  set -x color_path_nowrite             $base02 $base08
  set -x color_path_nowrite_basename    $base02 $base08 --bold

  set -x color_repo                     $base0B $colorfg
  set -x color_repo_work_tree           $base02 $colorfg --bold
  set -x color_repo_dirty               $base08 $colorfg
  set -x color_repo_staged              $base09 $colorfg

  set -x color_vi_mode_default          $base03 $colorfg --bold
  set -x color_vi_mode_insert           $base0B $colorfg --bold
  set -x color_vi_mode_visual           $base09 $colorfg --bold

  set -x color_vagrant                  $base0C $colorfg --bold
  set -x color_username                 $base02 $base0D --bold
  set -x color_hostname                 $base02 $base0D
  set -x color_rvm                      $base08 $colorfg --bold
  set -x color_virtualfish              $base0D $colorfg --bold
  set -x color_virtualgo                $base0D $colorfg --bold
  set -x color_desk                     $base0D $colorfg --bold
end
