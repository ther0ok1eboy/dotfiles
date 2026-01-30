return {
  {
    "nvim-neo-tree/neo-tree.nvim",
    branch = "v3.x",
    dependencies = {
      "nvim-lua/plenary.nvim",
      "nvim-tree/nvim-web-devicons",
      "MunifTanjim/nui.nvim",
    },
    cmd = "Neotree",
    keys = {
      {
        "tt",
        "<cmd>Neotree toggle<CR>",
        desc = "Toggle Neo-tree",
      },
    },
    init = function()
      -- Neovim 启动完成后再打开 Neo-tree
      vim.schedule(function()
        vim.cmd("Neotree filesystem show left")
      end)
    end,
  },
}
