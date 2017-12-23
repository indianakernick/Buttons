local common = import "common.jsonnet";
local tileSize = 20;
local glyphWidth = 5;
local glyphHeight = 7;

function(params) {
  components: common.checkParams(params, ["font scale", "pos", "text"]) {
    TextRendering: {
      sprite: "char 0",
      
      local scale =
        if "font scale" in params then
          params["font scale"]
        else
          1
      ,
      
      scale: [scale * glyphWidth / tileSize, scale * glyphHeight / tileSize],
      kern: scale / tileSize,
      depth: common.getDepth("text")
    },
    Transform: common.getPos(params),
    Text: common.stringToIndicies(params.text)
  }
}
