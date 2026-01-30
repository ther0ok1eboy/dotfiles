return {
  {
    "lambdalisue/suda.vim",
    -- 可选配置项
    config = function()
      -- 如果需要额外配置，可以在这里添加
      -- 例如：vim.g.suda_smart_edit = 1
    end,
    -- 按需加载（可选）
    event = "BufReadPre", -- 在读取文件前加载
  },
}
