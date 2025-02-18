-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here

-- Common use

-- grug-far.nvim
-- <leader>sr Search and Replace

-- fzf-lua
-- <leader><space> Find Files (Root Dir)

-- neo-tree.nvim
-- <leader>e Buffer Explorer

-- snacks.nvim
-- <leader>n Notification History
-- <leader>un Dismiss All Notifications

local map = LazyVim.safe_keymap_set

-- Move
map("n", "e", "l", { desc = "Right", remap = true })
map("n", "q", "h", { desc = "Left", remap = true })
map("n", "J", "5j", { desc = "better Up", remap = true })
map("n", "K", "5k", { desc = "better Down", remap = true })

-- Move to window using the <ctrl> hjkl keys
map("n", "<C-j>", "<C-w>h", { desc = "Go to Lower Window", remap = true })
map("n", "<C-k>", "<C-w>l", { desc = "Go to Upper Window", remap = true })

-- Buffers
map("n", "<A-j>", "<cmd>bprevious<cr>", { desc = "Prev Buffer" })
map("n", "<A-k>", "<cmd>bnext<cr>", { desc = "Next Buffer" })

-- Opt
map("n", "Q", "<cmd>q!<cr>", { desc = "Quit without save" })

-- Vim table mode
map("n", "<leader>tm", "<cmd>TableModeToggle<cr>", { desc = "start vim table mode" })
